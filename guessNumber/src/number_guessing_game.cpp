// FUNCTION generateRandomNumber(min, max)
//     CREATE random engine
//     RETURN random number in range
// END

// FUNCTION readValidGuess
//     READ input
//     IF invalid
//         CLEAR buffer
//         RETURN invalid
//     END
//     RETURN input
// END

// FUNCTION startGame
//     SET secret number
//     SET attempts = 0

//     LOOP
//         GET guess
//         IF invalid → continue
//         attempts++

//         IF guess < secret → print "Too low"
//         ELSE IF guess > secret → print "Too high"
//         ELSE
//             print "Correct"
//             print attempts
//             STOP
//         END
//     END LOOP
// END
