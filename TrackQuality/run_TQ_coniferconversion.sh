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


python conifer_converter.py xgboost_model.pkl

mv simdir/firmware/parameters.h .
mv simdir/firmware/BDT.h .

rm -r simdir

mkdir ../emData/TQ
cp hls_hex.dat ../emData/TQ
cp conifer_predictions.dat ../emData/TQ


