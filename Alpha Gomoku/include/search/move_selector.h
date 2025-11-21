#ifndef GOMOKU_SEARCH_MOVE_SELECTOR_H
#define GOMOKU_SEARCH_MOVE_SELECTOR_H

#include <vector>
#include "core/board.h"
#include "search/search_types.h"
#include "tactics/threat_solver.h"
#include "search/history_heuristic.h"

namespace gomoku {

class MoveSelector {
public:
    // Generate moves at the current node.
    // Handles threat solver restrictions (forced defenses) automatically.
    static std::vector<Move> generateMoves(const Board& board,
                                           const ThreatAnalysis& threatInfo);

    // Sort moves in-place by descending promise.
    static void orderMoves(Player sideToMove,
                           std::vector<Move>& moves,
                           const Move& ttMove,
                           const Move& pvMove,
                           const ThreatAnalysis& threatInfo,
                           const IHistoryHeuristic* history);
};

} // namespace gomoku

#endif // GOMOKU_SEARCH_MOVE_SELECTOR_H