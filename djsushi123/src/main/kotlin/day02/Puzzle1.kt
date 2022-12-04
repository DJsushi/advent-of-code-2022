package day02

import java.io.File

enum class Result {
    WON, LOST, DRAW;

    companion object {
        fun from(string: String) = when (string) {
            "X" -> LOST
            "Y" -> DRAW
            "Z" -> WON
            else -> error("Input error.")
        }
    }
}

enum class Toss(val value: Int) {
    ROCK(1), PAPER(2), SCISSORS(3);

    companion object {
        fun from(string: String) = when (string) {
            in "AX" -> ROCK
            in "BY" -> PAPER
            in "CZ" -> SCISSORS
            else -> error("Input error.")
        }

        private fun findResult(opponent: Toss, player: Toss) = when (player.ordinal - opponent.ordinal) {
            1, -2 -> Result.WON
            0 -> Result.DRAW
            else -> Result.LOST
        }

        fun findToss(opponent: Toss, result: Result): Toss = when (result) {
            Result.WON -> when (opponent) {
                ROCK -> PAPER
                PAPER -> SCISSORS
                SCISSORS -> ROCK
            }
            Result.DRAW -> opponent
            Result.LOST -> when (opponent) {
                ROCK -> SCISSORS
                PAPER -> ROCK
                SCISSORS -> PAPER
            }
        }

        /**
         * Find the number of points that a certain game would yield to the player.
         */
        fun evaluate(opponent: Toss, player: Toss): Int {
            return player.value + when (findResult(opponent, player)) {
                Result.WON -> 6
                Result.DRAW -> 3
                Result.LOST -> 0
            }
        }
    }
}

object Day02 {
    private val input = File("src/main/resources/day02/input")
        .readLines()
        .map { it.split(" ") }

    fun puzzle1(): Int {
        return input
            .map { Toss.from(it[0]) to Toss.from(it[1]) }
            .sumOf { Toss.evaluate(it.first, it.second) }
    }

    fun puzzle2(): Any {
        return input
            .map { Toss.from(it[0]) to Result.from(it[1]) }
            .sumOf { Toss.evaluate(it.first, Toss.findToss(it.first, it.second)) }
    }
}
