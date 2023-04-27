// DuplicateRemoval test bench
#include "../TopFunctions/DuplicateRemovalTop.h"

#include <vector>
#include <sstream>

using namespace dr;
using namespace std;

constexpr int numTracks = 5;

constexpr int valids[numTracks][numLayers] = {
  {0, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};
constexpr int ids[numTracks][numLayers] = {
  {00, 17, 12, 06, 89, 41, 05},
  {21, 00, 02, 18, 01, 02, 03},
  {21, 17, 00, 06, 89, 14, 15},
  {18, 05, 03, 00, 13, 02, 03},
  {03, 05, 03, 47, 00, 02, 03}
};
constexpr bool uniques[numTracks] = {
  true, true, false, true, false
};

void print(const vector<TrackOut>& tracks, stringstream& ss) {
  for (const TrackOut& track : tracks) {
    ss << track.reset_ << " ";
    ss << track.valid_ << " ";
    ss << setw(2) << track.data_ << " | ";
    for (const StubOut& stub : track.stubs_) {
      ss << stub.valid_ << " ";
      ss << setw(2) << stub.data_ << " | ";
    }
    ss << endl;
  }
}


int main(){

  const TrackIn null = TrackIn();
  TrackOut tmp;
  vector<TrackIn> tracksIn(numTracks + 1);
  vector<TrackOut> tracksOut(numTracks + 1);
  vector<TrackOut> tracksExp(numTracks + 1);

  for (int i = 0; i < numTracks; i++) {
    tracksIn[i + 1].valid_ = 1;
    tracksIn[i + 1].data_ = i * 10 + 2;
    for (int j = 0; j < numLayers; j++) {
      tracksIn[i + 1].stubs_[j].valid_ = valids[i][j];
      tracksIn[i + 1].stubs_[j].id_ = ids[i][j];
      tracksIn[i + 1].stubs_[j].data_ = i * 5 + j;
    }
  }
  tracksIn[0].reset_ = 1;

  Track track;
  for (int i = 0; i < numTracks; i++) {
    track = uniques[i] ? tracksIn[i + 1] : TrackIn();
    tracksExp[i + 1] = track;
  }
  track = tracksIn[0];
  tracksExp[0] = track;

  for (int tick = 0; tick < numTracks + 1 + numComparisonModules - 1; tick++) {
    const TrackIn& trackIn = tick < numTracks + 1 ? tracksIn[tick] : null;
    TrackOut& trackOut = tick >= numComparisonModules - 1 ? tracksOut[tick - numComparisonModules + 1] : tmp;
    DuplicateRemovalTop(trackIn, trackOut);
  }

  stringstream ssExp, ssSim;
  print(tracksExp, ssExp);
  print(tracksOut, ssSim);

  cout << "Expectation:" << endl << ssExp.str();
  cout << "Simulation:" << endl << ssSim.str();

  return ssExp.str() == ssSim.str() ? 0 : 1;

}