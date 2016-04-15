#ifndef BOARD_ALIGNER_H
#define BOARD_ALIGNER_H

#include <memory>
#include <vector>

#include "vector2d.h"
#include "circlePatternGenerator.h"
#include "selectableGeometryFeatures.h"
#include "typesafeBitmaskEnums.h"

using std::vector;
using corecvs::Vector2dd;
using corecvs::RGB24Buffer;

enum class AlignmentType
{
    FIT_ALL,                /**< Fit all = fit 2 dimensions regardless of orientations    */
    FIT_WIDTH,              /**< Fit width = fit width (e.g. dimension along X axis)      */
    FIT_HEIGHT,             /**< Fit height = fit height (e.g. dimension along Y)         */
    FIT_MARKER_ORIENTATION, /**< Keep orientaion and select position using central marker */
    FIT_MARKERS             /**< Detect orientation                                       */
//    // Detect orientation and board ids
//    FIT_MARKERS_MULTIPLE
};

struct BoardMarkerDescription
{
    int cornerX;
    int cornerY;
    vector<Vector2dd> circleCenters;
    double circleRadius;
    int boardId;

    BoardMarkerDescription() {
        DefaultSetter setter;
         accept(setter);
    }

    template<typename VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit(cornerX, 0, "cornerX");
        visitor.visit(cornerY, 0, "cornerY");
        visitor.visit(circleCenters, "circleCenters");
        visitor.visit(circleRadius, 0.08, "circleRadius");
        visitor.visit(boardId, 0, "boardId");
    }

};

struct BoardAlignerParams
{
    AlignmentType type = AlignmentType::FIT_WIDTH;
    vector<BoardMarkerDescription> boardMarkers;
    int idealWidth  = 18;
    int idealHeight = 11;

    template<typename VisitorType>
    void accept(VisitorType &visitor)
    {
        auto m = asInteger(type);
        visitor.visit(m, m, "alignmentType");
        type = static_cast<AlignmentType>(m);
        visitor.visit(idealWidth  , 18, "idealWidth");
        visitor.visit(idealHeight , 11, "idealHeight");
        visitor.visit(boardMarkers, "boardMarkers");
    }

    static BoardAlignerParams GetIndoorsBoard();
    static BoardAlignerParams GetOldBoard();
    static BoardAlignerParams GetNewBoard();
};


class BoardAligner : public BoardAlignerParams
{
public:
    BoardAligner(BoardAlignerParams params = BoardAlignerParams());
    BoardAligner(BoardAlignerParams params, const std::shared_ptr<CirclePatternGenerator> &sharedGenerator);


    void setAlignerParams(const BoardAlignerParams &params);
    BoardAlignerParams getAlignerParams(void);


    bool align(DpImage &img);
    void drawDebugInfo(RGB24Buffer &buffer);

    vector<vector<Vector2dd>>      bestBoard;

    static CirclePatternGenerator* FillGenerator(const BoardAlignerParams &params);

protected:
    std::shared_ptr<CirclePatternGenerator> generator;
    bool                                    sharedGenerator;
    vector<vector<std::pair<int, int>>>     classifier;
    vector<vector<std::pair<int, int>>>     initialClassifier;

public:
    corecvs::ObservationList                observationList;

    void printClassifier(bool initial);

private:
    int patternIdentity;
    bool alignDim(DpImage &img, bool fitW, bool fitH);
    bool alignSingleMarker(DpImage &img);
    bool alignMarkers(DpImage &img);
    void classify(bool trackOrientation, DpImage &img);
    void fixOrientation();
    void transpose();
    bool bfs();
    bool createList();
};

#endif // BOARD_ALIGNER_H
