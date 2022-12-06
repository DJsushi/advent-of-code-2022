import day06.Day06
import kotlin.test.Test
import kotlin.test.assertEquals

class Day06Test {

    @Test
    fun `Day06 Puzzle1`() {
        val day06 = Day06()
        assertEquals(1848, day06.puzzle01())
    }

    @Test
    fun `Day06 Puzzle2`() {
        val day06 = Day06()
        assertEquals(2308, day06.puzzle02())
    }
}