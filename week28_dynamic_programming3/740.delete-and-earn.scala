object Solution {
    def deleteAndEarn(nums: Array[Int]): Int = {
      // 先排序，有两个状态，选sel与不选nosel
      // 对于当前状态s
      // sel_next = nosel_old + s
      // nosel_next = max(sel_old, nosel_old)
      // 由于nums[i]在[1, 10000]之间
      val scores = Array.fill(10001)(0)
      nums.foreach(x => scores(x) += x)
      var res = scores.foldLeft((0, 0)) {
        case ((sel, nosel), score) => {
          (nosel + score) -> sel.max(nosel) // A -> B指返回二元组(A, B)
        }
      }
      math.max(res._1, res._2)
    }
}
