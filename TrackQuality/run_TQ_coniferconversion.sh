if [ -d "conifer" ]
then
    echo "Conifer already present"
else 
    git clone https://github.com/thesps/conifer.git
    cd conifer
    pip install .
    cd ..
fi

python -c "import joblib"
RESULT=$?
if [ $RESULT -eq 1 ]; then 
  echo "Install python package Joblib to run"
  exit 1
fi

python -c "import numpy"
RESULT=$?
if [ $RESULT -eq 1 ]; then
  echo "Install python package Numpy to run"
  exit 1
fi

python -c "import xgboost"
RESULT=$?
if [ $RESULT -eq 1 ]; then
  echo "Install python package Xgboost to run"
  exit 1
fi


if [ -d "simdir" ]
then
  rm -r simdir
fi

if [ -d "hlsdir" ]
then
  rm -r hlsdir
fi

TrackQuality_url="https://cernbox.cern.ch/index.php/s/7Zo8KfaPZ7ySIt8/download"

if [ -f "xgboost_model.pkl" ]
then
  echo "Model Present"
else
  echo "No Model Present" 
  wget -O TQ.tar.gz --quiet ${TrackQuality_url}
  tar -xzf TQ.tar.gz
  rm -f TQ.tar.gz
  mv TQ/* .
fi

python conifer_converter.py xgboost_model.pkl

mv simdir/firmware/parameters.h .
mv simdir/firmware/BDT.h .

rm -r simdir

mv hls_features.dat TQ/
mv hls_hex.dat TQ/
mv conifer_predictions.dat TQ/


