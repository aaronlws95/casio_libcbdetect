#include "libcbdetect/get_boards.h"

namespace cbdetect {

void get_boards(const cv::Mat& img, std::vector<std::vector<std::vector<int>>>& boardIdx, std::vector<cv::Point2d>& cornerPoints)
{
    Corner libcbCorners;
    Params libcbParams;
    std::vector<Board> libcbBoards;

    boardIdx.clear();
    cornerPoints.clear();

    find_corners(img, libcbCorners, libcbParams);

    if (libcbCorners.p.empty())
    {
        return;
    }

    boards_from_corners(img, libcbCorners, libcbBoards, libcbParams);

    for (int i = 0; i< libcbBoards.size(); i++)
    {
        boardIdx.push_back(libcbBoards[i].idx);
    }

    cornerPoints = libcbCorners.p;
}

}