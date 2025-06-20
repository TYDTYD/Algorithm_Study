# [Silver II] 실수 - 24057 

[문제 링크](https://www.acmicpc.net/problem/24057) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

유클리드 호제법, 구현, 수학, 정수론

### 제출 일자

2025년 5월 2일 21:27:04

### 문제 설명

<p>$\displaystyle{b + c \sqrt{d} \over a}$</p>

<ul>
	<li>$a, \, b, \, c, \, d$는 정수</li>
	<li>$a > 0$; $0 \le d \ne 1$</li>
	<li>$\gcd (a, \, b, \, c) = 1$</li>
	<li>'$c = 0$'과 '$d = 0$'는 필요충분조건</li>
	<li>$d > 0$일 때 $d$의 약수 중 $1$보다 큰 제곱수가 없음</li>
</ul>

<p>위 형식으로 표현되는 실수 $A$와 $B$가 주어질 때, $A+B$, $A-B$, $A \times B$, $A \div B$의 값을 출력하는 프로그램을 작성하세요.</p>

### 입력 

 <p>첫 번째 줄에 $A$의 $a, \, b, \, c, \, d$ 값이 하나씩 주어집니다.</p>

<p>두 번째 줄에는 마찬가지로 $B$의 $a, \, b, \, c, \, d$ 값이 하나씩 주어집니다.</p>

### 출력 

 <p>첫 번째 줄부터 네 번째 줄까지 각각 $A+B$, $A-B$, $A \times B$, $A \div B$의 값을 문제에서 설명한 형식으로 표현했을 때의 $a, \, b, \, c, \, d$ 값을 출력합니다.</p>

