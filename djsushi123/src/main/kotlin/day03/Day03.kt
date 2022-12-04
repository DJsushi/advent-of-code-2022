package day03

import java.io.File

object Day03 {

    private val input = File("src/main/resources/day03/input")
    private val processedInput = input.readLines()


    fun puzzle01(): Int {
        return processedInput
            .map { it.splitInHalf() }
            .map { it.findCommonItem() }
            .sumOf { it.findPriority() }
    }

    fun puzzle02(): Int {
        return processedInput
            .chunked(3)
            .map { findCommonItem(it[0], it[1], it[2]) }
            .sumOf { it.findPriority() }
    }
}

private fun String.splitInHalf() = Pair(substring(0..lastIndex / 2), takeLast(length / 2))

private fun Char.findPriority() = (('a'..'z') + ('A'..'Z')).indexOf(this) + 1

private fun findCommonItem(rucksack1: String, rucksack2: String, rucksack3: String): Char {
    for (item1 in rucksack1) {
        for (item2 in rucksack2) {
            for (item3 in rucksack3) {
                if (item1 == item2 && item2 == item3) return item1
            }
        }
    }
    // Shouldn't happen
    error("Didn't fidn a common item.")
}

private fun Pair<String, String>.findCommonItem(): Char {
    first.forEach { firstCompartmentItem ->
        if (second.any { it == firstCompartmentItem }) return firstCompartmentItem
    }
    println(this)
    error("Didn't find any common letter.")
}