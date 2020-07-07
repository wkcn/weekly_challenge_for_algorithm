import util.control.Breaks._

object Solution {
  // 要记得有怎么表示状态，这里的状态包括(已经使用的数字，当前和)
  // 以及记得状态的转换条件
  def canIWin(maxChoosableInteger: Int, desiredTotal: Int): Boolean = {
    if (maxChoosableInteger >= desiredTotal) return true
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false
    val num_states = (1 << maxChoosableInteger)
    // 状态应该是每个数被使用的情况，而不是当前的累加数
    var dp = new Array[Boolean](num_states)
    var vis = new Array[Boolean](num_states)

    def win(state: Int, su: Int): Boolean = {
      if (vis(state)) return dp(state)
      var can_win = false
      breakable {
        for (i <- (1 to maxChoosableInteger).reverse) {
          val mask = 1 << (i - 1)
          if ((state & mask) == 0) {
            val next_su = su + i
            if (next_su >= desiredTotal) {
              can_win = true
              break()
            }
            val next = state | mask
            if (!win(next, next_su)) {
              // 选择了一个下一个玩家不能胜利的状态
              can_win = true
              break()
            }
          }
        }
      }
      vis(state) = true
      dp(state) = can_win
      can_win
    }

    win(0, 0)
  }

  def main(args: Array[String]): Unit = {
    assert(canIWin(3, 6) == true)
    assert(canIWin(10, 11) == false)
    assert(canIWin(4, 6) == true)
  }
}
