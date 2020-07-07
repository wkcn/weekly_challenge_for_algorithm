object Solution2 {
    def waysToStep(n: Int): Int = {
      if (n < 0) {
        return 0
      }
      var mod = 1000000007
      // dp[i] = dp[0] + dp[1] + dp[2]
      var dp = new Array[Int](n.max(3) + 1)
      dp(0) = 0
      dp(1) = 1
      dp(2) = 2
      dp(3) = 4
      4 to n foreach {
        i => dp(i) = ((dp(i - 1) + dp(i - 2)) % mod + dp(i - 3)) % mod
      }
      dp(n)
    }
    def main(args: Array[String]): Unit = {
      val n = 10
      println(waysToStep(n))
    }
}

// 因为MOD已经很大了，即使先去模，乘法也会溢出
object Solution {
  type Mat = Array[Array[Long]]
  def waysToStep(n: Int): Int = {
    val x: Array[Long] = Array(1, 2, 4)
    if (n <= 0) return 0
    if (n <= 3) return x(n - 1).toInt
    val A: Mat = Array(Array(0, 1, 0),
                       Array(0, 0, 1),
                       Array(1, 1, 1))
    val Ap = matPow(A, n - 3)
    var res: Long = 0
    (0 until 3) foreach { i => 
      res = (res + Ap(2)(i) * x(i)) % MOD
    }
    return res.toInt
  }
  private def matMul(a: Mat, b: Mat): Mat = {
    val res = Array.ofDim[Long](a.length, b(0).length)
    // res[i, j] = sum_k (a[i, k] * b[k, j])
    a.indices.foreach(i =>
        b(0).indices.foreach(j =>
            a(0).indices.foreach(k =>
                res(i)(j) = (res(i)(j) + a(i)(k) * b(k)(j)) % MOD
            )
        ) 
    )
    res
  }
  private def matPow(a: Mat, n: Int): Mat = {
    if (n == 1) return a
    var x = matPow(a, n / 2)
    var res: Mat = Array.ofDim(3, 3)
    if (n % 2 == 1) {
      res = matMul(matMul(x, x), a)
    } else {
      res = matMul(x, x)
    }
    res
  }
  var MOD = 1000000007

  def main(args: Array[String]): Unit = {
    val n = 61
    println(waysToStep(n))
  }
}
