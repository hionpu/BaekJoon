/*
 * 백준 1786번: 찾기 (Find)
 * 
 * 이 프로그램은 문자열 T에서 패턴 문자열 P가 몇 번, 어느 위치에서 나타나는지 찾는 문제를 해결합니다.
 * KMP(Knuth-Morris-Pratt) 알고리즘을 사용하여 효율적으로 문자열 매칭을 수행합니다.
 * 
 * KMP 알고리즘은 O(N+M) 시간 복잡도를 가지며, 실패 함수(pi 배열)를 이용해 불필요한 비교를 건너뛰는 방식으로 동작합니다.
 */

#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

/**
 * computePi 함수: 패턴 문자열의 실패 함수(pi 배열)를 계산합니다.
 * 
 * @param P 패턴 문자열
 * @return 계산된 pi 배열
 * 
 * pi[i]는 P[0...i]의 접두사이면서 접미사인 문자열의 최대 길이를 나타냅니다.
 * 이 값은 패턴 매칭 중 불일치가 발생했을 때 다음으로 비교할 위치를 결정하는 데 사용됩니다.
 */
static vector<int> computePi(string P) {
	vector<int> pi(P.length(), 0);  // pi 배열을 0으로 초기화합니다.
	int m = P.length();
	int j = 0;  // 접두사 포인터
	
	for (int i = 1; i < m; ++i)  // i는 접미사 포인터로, 1부터 시작합니다.
	{
		// 불일치가 발생한 경우, j를 이전까지의 일치 정보를 활용하여 뒤로 이동시킵니다.
		while (j > 0 && P[i] != P[j])
		{
			j = pi[j - 1];
		}

		// 현재 문자가 일치하면 j를 증가시키고 pi[i]에 저장합니다.
		if (P[i] == P[j])
		{
			pi[i] = ++j;
		}
	}

	return pi;
}

// 전역 변수: 패턴이 등장한 횟수와 위치를 저장합니다.
int occur = 0;  // 패턴이 발견된 총 횟수
vector<int> pos;  // 패턴이 발견된 시작 위치들

/**
 * KMP 함수: KMP 알고리즘을 사용하여 문자열 T에서 패턴 P를 찾습니다.
 * 
 * @param T 탐색할 대상 문자열
 * @param P 찾을 패턴 문자열
 * 
 * 알고리즘이 패턴을 찾으면 전역 변수 occur을 증가시키고 
 * 해당 위치를 pos 벡터에 저장합니다.
 */
static void KMP(string T, string P) {
	vector<int> pi = computePi(P);  // 패턴의 실패 함수(pi 배열)를 계산합니다.
	int j = 0;  // 패턴의 비교 위치를 나타내는 인덱스

	for (int i = 0; i < T.length(); ++i)  // 문자열 T를 처음부터 끝까지 순회합니다.
	{
		// 불일치가 발생하면 j를 적절히 뒤로 이동시켜 불필요한 비교를 건너뜁니다.
		while (j > 0 && T[i] != P[j])
		{
			j = pi[j - 1];
		}
		
		// 현재 문자가 일치하는 경우
		if (T[i] == P[j])
		{
			// 패턴의 끝에 도달했다면 패턴을 찾은 것입니다.
			if (j == P.length() - 1)
			{
				occur++;  // 발견 횟수 증가
				pos.push_back(i - j + 1);  // 패턴이 시작된 위치 저장 (1-기반 인덱스)
				j = pi[j];  // 다음 탐색을 위해 j를 이동시킵니다.
			}
			else
			{
				j++;  // 아직 패턴의 끝이 아니면 다음 문자를 비교하기 위해 j를 증가시킵니다.
			}
		}
	}
}

int main() {
	// 입출력 최적화: C++ 표준 입출력과 C 표준 입출력 동기화를 끊어 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(0);  // cin과 cout의 묶음을 풀어 입출력 속도를 높입니다.
	cout.tie(0);

	string T, P;  // T: 탐색할 문자열, P: 찾을 패턴
	getline(cin, T);  // 한 줄 전체를 입력받습니다.
	getline(cin, P);

	KMP(T, P);  // KMP 알고리즘을 실행합니다.

	// 결과 출력
	cout << occur << '\n';  // 패턴이 등장한 총 횟수 출력
	for (auto& p : pos)  // 각 발견된 위치 출력
	{
		cout << p << ' ';
	}
	cout << '\n';
	return 0;
}