# Changes: Original vs Improved Code

This document highlights the key differences between your original code and the improved version.

## Methods to View Diffs in Cursor

### Method 1: Git Diff (Terminal)
```bash
# View changes to modified files
git diff src/main.cpp
git diff src/number_guessing_game.cpp

# View all changes
git diff

# Compare improved.cpp sections with originals (manual extraction needed)
```

### Method 2: Cursor IDE Built-in Features
1. **Source Control Panel**: 
   - Click the Source Control icon (left sidebar)
   - Click on modified files to see diff view
   - Green = additions, Red = deletions

2. **Compare Files**:
   - Right-click on a file → "Open to the Side"
   - Open both files side-by-side to compare

3. **GitLens Extension** (if installed):
   - Shows inline diffs
   - File history and blame

### Method 3: Terminal Diff Command
```bash
# Compare two files
diff -u src/main.cpp improved.cpp

# Side-by-side comparison
diff -y src/main.cpp improved.cpp

# Colored diff (if available)
diff --color=always src/main.cpp improved.cpp
```

---

## Key Changes Summary

### 1. main.cpp Changes

#### Added Missing Return Statements
**Before:**
```cpp
if(argc != 2) {
  std::cerr << "Usage: ./number_guessing_game <integer>";
  // Missing return!
}
```

**After:**
```cpp
if(argc != 2) {
  std::cerr << "Usage: ./number_guessing_game <integer>\n";
  return 1;  // ✅ Added
}
```

#### Added Return on Success
**Before:**
```cpp
startGame(game_ceiling);
// Missing return 0
```

**After:**
```cpp
startGame(game_ceiling);
return 0;  // ✅ Added
```

#### Improved Error Handling
**Before:**
```cpp
} catch(const std::exception& ex){
  std::cout << "Error: " << ex.what() << std::endl;
}
```

**After:**
```cpp
} catch (const std::out_of_range&) {
  std::cerr << "Error: Input value is too large for an integer.\n";
  return 1;
} catch (const std::invalid_argument&) {
  std::cerr << "Error: Invalid input. Must be an integer.\n";
  return 1;
} catch (const std::exception& ex) {
  std::cerr << "Error: " << ex.what() << "\n";
  return 1;
}
```

### 2. number_guessing_game.cpp Changes

#### Fixed Attempt Counting Bug
**Before:**
```cpp
while (true){
  attempts++;  // ❌ Counts invalid inputs
  std::string guess{ };
  std::cin >> guess;
  int guessValue { convertInteger(guess) };
  if(guessValue == -1) {
    std::cout << "Value guessed is invalid...\n";
    // Still counts as attempt!
  }
  // ...
  // attempts++ at wrong position - correct guess not counted
}
```

**After:**
```cpp
while (true){
  std::string input;
  // ... read input ...
  int guessValue = readValidGuess(input);
  
  if (guessValue == INVALID_GUESS) {
    std::cout << "Invalid input...\n";
    continue;  // ✅ Skip counting invalid inputs
  }
  
  attempts++;  // ✅ Only count valid guesses
  
  if (guessValue < randomValue) {
    // ...
  }
}
```

#### Const Correctness
**Before:**
```cpp
int convertInteger(std::string& guess)  // ❌ Non-const reference
```

**After:**
```cpp
int readValidGuess(const std::string& input)  // ✅ Const reference
```

#### Named Constants Instead of Magic Numbers
**Before:**
```cpp
return -1;  // ❌ Magic number
if(guessValue == -1) {
```

**After:**
```cpp
constexpr int INVALID_GUESS = -1;  // ✅ Named constant
return INVALID_GUESS;
if (guessValue == INVALID_GUESS) {
```

#### Better Error Messages
**Before:**
```cpp
std::cout << "Value guessed is more than actual...\n";
std::cout << "Value guessed is less than actual...\n";
```

**After:**
```cpp
std::cout << "Too high\n";  // ✅ Matches requirements
std::cout << "Too low\n";   // ✅ Matches requirements
```

#### Additional Error Handling
**Before:**
```cpp
// No EOF handling
// No range validation
```

**After:**
```cpp
if (std::cin.eof()) {
  std::cout << "\nGame ended (EOF detected).\n";
  break;
}
if (max < 1) {
  std::cerr << "Error: Maximum number must be at least 1.\n";
  return;
}
```

---

## Quick Command Reference

```bash
# View git diff
git diff

# View specific file diff
git diff src/main.cpp

# View all changes staged/unstaged
git diff HEAD

# Compare specific sections (using grep/sed)
grep -n "functionName" original.cpp improved.cpp

# View file side-by-side in terminal
diff -y original.cpp improved.cpp | less
```
