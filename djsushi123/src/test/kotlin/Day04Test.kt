import day04.Day04
import kotlin.test.Test
import kotlin.test.assertEquals

class Day04Test {

    @Test
    fun `Day04 Puzzle1`() {
        assertEquals(542, Day04.puzzle01())
    }

    @Test
    fun `Day04 Puzzle2`() {
        assertEquals(900, Day04.puzzle02())
    }
}