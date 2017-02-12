## record of my acm trace


###Auto compile file and auto input data
add following to your `$VIMRUNTIM/vimrc`
```
" make
set makeprg=g++\ -Wall\ \ %
nmap <silent> <F6> :make<CR><CR>
nmap <silent> <F7> :call Do_Make()<CR>
function! Do_Make()
    execute "!./a.out < a.in"
endfunction
```

- `<F6>`: compile current file, then get a.out
- `<F7>`: input a.in into a.out
- `a.in`: test data

###sizeof()
```
int nums[10];
printf("%d %d", (int)sizeof(nums), (int)sizeof(int) * 10);
```
the result is `40 40`, that means that `sizeof(nums)` equals `sizeof(int) * 10`

###memset()
```
int nums[10];
memset(nums, 0, sizeof(nums));  //set every number in nums to 0
memset(nums, -1, sizeof(nums)); //set every number in nums to -1
memset(nums, 0xff, sizeof(nums)); //set every number in nums to -1
```

###test.sh usage
>>####test.sh

>>        g++ $1
>>        ./a.out<a.in

>>####how to use

>>       . test.sh file.cc
>>或者

>>        sh test.sh file.cc

###summary
>>1 max unsigend long long is 64bit, 0xffffffffffffffff, 大于`1.84*10^20`
