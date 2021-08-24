// MIT License

// Copyright (c) 2021 FenglinZhou

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "ratelimiter.h"
#include <iostream>
#include <unistd.h>

#define SIZE 100

int main(int argc, char** argv){
    std::cout << std::atoi(argv[1]) << std::endl;
    RateLimiter::GetInstance()->SetCapacity(std::atoi(argv[1]));
    sleep(1);
    for (int i = 0; i < SIZE; ++i){
        if(RateLimiter::GetInstance()->MustGetToken()){
            std::cout << i << " is ok!\n";
        }else{
            std::cout << i << "failed!\n";
        }
    }
    std::cout << "failed count : " << 
        RateLimiter::GetInstance()->GetFailedCount() << std::endl;
    return 0;
}
