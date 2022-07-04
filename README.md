```                      
 
          ____  __ __  _____ __ __   _____ __    __   ____  ____  
         |    \|  T  T/ ___/|  T  T / ___/|  T__T  T /    T|    \ 
         |  o  )  |  (   \_ |  l  |(   \_ |  |  |  |Y  o  ||  o  )
         |   _/|  |  |\__  T|  _  | \__  T|  |  |  ||     ||   _/ 
         |  |  |  :  |/  \ ||  |  | /  \ |l  `  '  !|  _  ||  |   
         |  |  l     |\    ||  |  | \    | \      / |  |  ||  |   
         l__j   \__,_j \___jl__j__j  \___j  \_/\_/  l__j__jl__j  


```

##  🍀 push_swapとは？
スタック2本と指定されたコマンドを使って、少ない手数で数列をソートする課題です。  

##  🆗 使用してもよい関数
read, write, malloc, free, exit<br>
また、[norminette](https://github.com/42School/norminette)という42独自のコーディング規約に従う必要があります。<br>
norminetteの仕様でインデントがずれていたり変数のスコープが大きくなっていたりします。


##  ✅ ベンチマーク
【arg_length=5】    Max:10 Median:8<br>
【arg_length=100】  Median:540<br>
【arg_length=500】  Median:3810<br>

##  🔗 説明スライド
[push_swap](https://docs.google.com/presentation/d/13NAZS1wEtuRNTje_rvgyEfMTKCK4ryFImV-RLo8Z1C8/edit?usp=sharing)

## ⭐ USAGE

##### clone
```bash
git clone https://github.com/mayocorn/push_swap.git mayocorn/push_swap
```

##### build push_swap & checker
```bash
cd mayocorn/push_swap
make
make bonus
```

##### run
```bash
./push_swap 5 4 1 3 2
```
```bash
./push_swap 5 4 1 3 2 | ./checker 5 4 1 3 2
```

##### sample
https://user-images.githubusercontent.com/89581623/177196954-b30c601c-b6e2-46b0-8cdb-4f4354840174.mp4



