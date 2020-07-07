object Solution {
  def minimumDistance_naive(word: String): Int = {
    if (word.length == 0) return 0
    // 首先先计算两两字母的距离
    def getPos(w: Int) = (w / 6, w % 6)
    def getDis(a: (Int, Int), b: (Int, Int)): Int = {
      (a._1 - b._1).abs + (a._2 - b._2).abs
    }
    var distances = Array.ofDim[Int](26, 26) 
    for (i <- 0 until 26) {
      val posA = getPos(i)
      for (j <- 0 until 26) {
        val posB = getPos(j)
        distances(i)(j) = getDis(posA, posB)
      }
    }
    // dp[t][i][j]表示已经输入了t个字母, 当前手指在i和j
    val maxVal = 12 * word.length
    var dp = Array.fill(word.length + 1, 26, 26)(maxVal)
    // 设置初值
    for (i <- 0 until 26) {
      for (j <- 0 until 26) {
        dp(0)(i)(j) = 0
      }
    }
    for (k <- 0 until word.length) {
      // t = k + 1
      val c = (word(k) - 'A').toInt
      for (i <- 0 until 26) {
        for (j <- 0 until 26) {
          if (dp(k)(i)(j) != maxVal) {
            dp(k + 1)(c)(j) = math.min(dp(k + 1)(c)(j), dp(k)(i)(j) + distances(i)(c))
            dp(k + 1)(i)(c) = math.min(dp(k + 1)(i)(c), dp(k)(i)(j) + distances(j)(c))
          }
        }
      }
    }
    var best = maxVal
    for (i <- 0 until 26) {
      for (j <- 0 until 26) {
        best = math.min(best, dp(word.length)(i)(j))
      }
    }
    best
  }
  // 必然要一只手按在上一个字母上，我们只需要记录不在上一个字母的手的位置
  def minimumDistance(word: String): Int = {
    if (word.length == 0) return 0
    // 首先先计算两两字母的距离
    def getPos(w: Int) = (w / 6, w % 6)
    def getDis(a: (Int, Int), b: (Int, Int)): Int = {
      (a._1 - b._1).abs + (a._2 - b._2).abs
    }
    var distances = Array.ofDim[Int](26, 26) 
    for (i <- 0 until 26) {
      val posA = getPos(i)
      for (j <- 0 until 26) {
        val posB = getPos(j)
        distances(i)(j) = getDis(posA, posB)
      }
    }
    // dp[t][i]表示已经输入了(t + 1)个字母, 一只手在字母word[t - 1]上，另一只手在i上 
    val maxVal = 12 * word.length
    var dp = Array.fill(word.length, 26)(maxVal)
    // 设置初值, 这里假设以及输入了一个字母, 另一只手可以放在26个位置, 成本为0
    for (i <- 0 until 26) {
      dp(0)(i) = 0
    }
    // 注意这里的k和上面的方法的k不一样
    for (k <- 1 until word.length) {
      val last_c = (word(k - 1) - 'A').toInt
      val c = (word(k) - 'A').toInt
      for (i <- 0 until 26) {
        if (dp(k - 1)(i) != maxVal) {
          // 一只手在last_c上，另一只手在i上
          // last_c的手移动到c
          dp(k)(i) = math.min(dp(k)(i), dp(k - 1)(i) + distances(last_c)(c))
          // 另一只手从i移动到c, 注意下标的变化
          dp(k)(last_c) = math.min(dp(k)(last_c), dp(k - 1)(i) + distances(i)(c))
        }
      }
    }
    dp(word.length - 1).min
  }
  def main(args: Array[String]): Unit = {
    println(minimumDistance("CAKE"))
    println(minimumDistance("HAPPY"))
    println(minimumDistance("NEW"))
    println(minimumDistance("YEAR"))
  }
}
