package day04

import java.io.File

object Day04 {

    private val input = File("src/main/resources/day04/input")
    private val processedInput = input
        .readLines()
        .map {
            it.split(",").let { range ->
                Pair(range[0].split("-"), range[1].split("-"))
            }
        }
        .map { it.first.toPair().toRange() to it.second.toPair().toRange() }

    fun puzzle01(): Int {
        return processedInput.map {
            if (it.first.contains(it.second) || it.second.contains(it.first)) 1 else 0
        }.sum()
    }

    fun puzzle02(): Int {
        return processedInput.map {
            if (it.first.overlaps(it.second) || it.second.overlaps(it.first)) 1 else 0
        }.sum()
    }
}

private fun List<String>.toPair() = Pair(this[0], this[1])

private fun Pair<String, String>.toRange() = (first.toInt())..(second.toInt())

private fun ClosedRange<Int>.contains(range: ClosedRange<Int>): Boolean {
    return if (this.start <= range.start) {
        this.endInclusive >= range.endInclusive
    } else {
        this.endInclusive < range.endInclusive
    }
}

private fun ClosedRange<Int>.overlaps(range: ClosedRange<Int>): Boolean {
    return if (this.start < range.start) {
        this.endInclusive >= range.start
    } else this.start <= range.endInclusive
}