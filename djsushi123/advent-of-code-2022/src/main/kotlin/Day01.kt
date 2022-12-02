import java.io.File

fun main() {
    val maxElfCalories = File("src/main/resources/day01/input")
        .readText()
        .split("\n\n")
        .map { it.split(Regex("\n+")) }
        .map { elf -> elf.map { it.toInt() } }
        .sortedBy { it.sum() }
        .takeLast(3)
        .sumOf { it.sum() }

    println(maxElfCalories)
}