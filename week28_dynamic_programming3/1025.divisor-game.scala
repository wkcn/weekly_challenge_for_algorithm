object Solution {
    def divisorGame(N: Int): Boolean = {
        // N == 1时的输
        // N == 2时，选1, 必胜
        // 当N是奇数时，约数是奇数或者1, 下一轮是偶数
        // 当N是偶数时，约数可能是奇数、偶数、1， 最终拿到偶数的一定胜利，让对方每次都是奇数即可
        N % 2 == 0
    }
}
