object Solution2 {
    def minCostClimbingStairs(cost: Array[Int]): Int = {
      if (cost.length == 0) return 0
      if (cost.length == 1) return cost(0)
      var left = cost(0)
      var right = cost(1)
      (2 until cost.length) foreach { i =>
        val old_right = right
        right = left.min(right) + cost(i)
        left = old_right
      }
      left.min(right)
    }
}

object Solution {
    def minCostClimbingStairs(cost: Array[Int]): Int = {
      if (cost.length == 0) return 0
      if (cost.length <= 2) return cost.min
      var left = cost(0)
      var right = cost(1)
      for (i <- 2 until cost.length) {
        val tmp = cost(i) + math.min(left, right)
        left = right
        right = tmp
      }
      math.min(left, right)
    }
}
