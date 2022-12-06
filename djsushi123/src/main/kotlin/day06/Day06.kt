package day06

import java.io.File

class Day06 {

    private val input = File("src/main/resources/day06/input").readText().dropLast(1)

    fun puzzle01(): Int {
        val chars = mutableListOf<Char>()
        chars.addAll(input.substring(0 until 4).toList())

        if (chars.distinct().size == chars.size) {
            return 4
        }

        for (i in 1 until input.lastIndex - 3) {
            chars.removeFirst()
            chars.add(input[i + 3])
            if (chars.distinct().size == chars.size) {
                return i + 4
            }
        }
        error("No 4 different chars found.")
    }

    fun puzzle02(): Int {
        val chars = mutableListOf<Char>()
        chars.addAll(input.substring(0 until 14).toList())

        if (chars.distinct().size == chars.size) {
            return 14
        }

        for (i in 1 until input.lastIndex - 13) {
            chars.removeFirst()
            chars.add(input[i + 13])
            if (chars.distinct().size == chars.size) {
                return i + 14
            }
        }
        error("No 14 different chars found.")
    }
}