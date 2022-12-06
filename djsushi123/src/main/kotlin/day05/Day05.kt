package day05

import java.io.File

private typealias Crate = Char?
private typealias Pile = ArrayDeque<Crate>
private typealias Instruction = List<Int>

class Day05 {

    private val input = File("src/main/resources/day05/input").readText().split("\n\n")

    private val piles = input[0]
        .split("\n")
        .dropLast(1)
        .map(::parseCrateLine)
        .let(::transposeCrates)

    private val instructions = input[1]
        .split("\n")
        .dropLast(1)
        .map { instruction ->
            val regex = """\d+""".toRegex()
            regex.findAll(instruction).map { it.value.toInt() }.toList()
        }

    fun puzzle01(): String {
        // loop through the instructions and execute them
        for (instruction in instructions) {
            executeInstruction9000(instruction, false)
        }
        return buildString {
            for (crate in piles) {
                append(crate.last())
            }
        }
    }

    fun puzzle02(): String {
        // loop through the instructions and execute them
        for (instruction in instructions) {
            executeInstruction9000(instruction, true)
        }
        return buildString {
            for (crate in piles) {
                append(crate.last())
            }
        }
    }

    /**
     * Parses a line containing crate info into a list of 9 nullable characters
     */
    private fun parseCrateLine(line: String): List<Crate> {
        val parsed = MutableList<Char?>(9) { null }
        var charIndex = 1
        while (true) {
            if (charIndex >= line.length) return parsed
            if (line[charIndex] != ' ') parsed[charIndex / 4] = line[charIndex]
            charIndex += 4
        }
    }

    private fun transposeCrates(crates: List<List<Crate>>): List<Pile> {
        val piles = List(9) { ArrayDeque<Crate>() }
        for (crateLine in crates) {
            crateLine.forEachIndexed { index, crate ->
                if (crate != null) piles[index].addFirst(crate)
            }
        }
        return piles
    }

    private fun executeInstruction9000(instruction: Instruction, isNewCraneModel: Boolean) {
        val amount = instruction[0]
        val from = instruction[1] - 1
        val to = instruction[2] - 1

        if (isNewCraneModel) {
            moveCrates(from, to, amount)
        } else {
            repeat(amount) {
                moveCrate(from, to)
            }
        }
    }

    private fun moveCrate(from: Int, to: Int) {
        piles[to].add(piles[from].removeLast())
    }

    private fun moveCrates(from: Int, to: Int, amount: Int) {
        val tempStack = ArrayDeque<Crate>()
        repeat(amount) {
            println(piles[from])
            tempStack.add(piles[from].removeLast())
            println(tempStack)
        }
        repeat(amount) {
            piles[to].add(tempStack.removeLast())
        }
    }
}