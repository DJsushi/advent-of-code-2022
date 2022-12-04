import day03.Day03
import kotlin.test.Test
import kotlin.test.assertEquals

class Day03Test {

    @Test
    fun `Day03 Puzzle1`() {
        assertEquals(8153, Day03.puzzle01())
    }

    @Test
    fun `Day03 Puzzle2`() {
        assertEquals(2342, Day03.puzzle02())
    }
}