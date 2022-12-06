import day05.Day05
import kotlin.test.Test
import kotlin.test.assertEquals

class Day05Test {

    @Test
    fun `Day05 Puzzle1`() {
        val day05 = Day05()
        assertEquals("SBPQRSCDF", day05.puzzle01())
    }

    @Test
    fun `Day05 Puzzle2`() {
        val day05 = Day05()
        assertEquals("RGLVRCQSB", day05.puzzle02())
    }
}