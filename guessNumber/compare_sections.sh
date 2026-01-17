#!/bin/bash
# Helper script to extract sections from improved.cpp for comparison

echo "╔════════════════════════════════════════════════════════════════╗"
echo "║  EXTRACTING SECTIONS FROM improved.cpp FOR COMPARISON          ║"
echo "╚════════════════════════════════════════════════════════════════╝"
echo ""
echo "To compare main() function:"
echo "  Lines 123-153 in improved.cpp vs src/main.cpp"
echo ""
echo "To compare startGame() function:"
echo "  Lines 60-115 in improved.cpp vs src/number_guessing_game.cpp (lines 30-55)"
echo ""
echo "To compare readValidGuess() function:"
echo "  Lines 26-43 in improved.cpp vs src/number_guessing_game.cpp (lines 14-27)"
echo ""
echo "Quick terminal comparison commands:"
echo "  diff -y -W 120 <(sed -n '123,153p' improved.cpp) src/main.cpp | less"
echo "  diff -y -W 120 <(sed -n '60,115p' improved.cpp) <(sed -n '30,55p' src/number_guessing_game.cpp) | less"

