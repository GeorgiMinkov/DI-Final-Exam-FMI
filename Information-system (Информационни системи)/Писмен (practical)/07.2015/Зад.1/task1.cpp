/*
07/2015

задача 1.

Даден е двумерен масив img, с елементи от тип float, с размери М (≤ 10) реда и N (≤ 10) стълба.
Напишете функция subsample, която получава като аргументи M, N и масива img и която създава и 
извежда на екрана нов двумерен масив S, за който е изпълнено:
1. S има размери (М+1)/2 и (N+1)/2
2. Всеки елемент S[i][j] е равен на средно-аритметичното от елементите на входния масив разположени на позиции M[y][x], 
където i*2 ≤ y ≤ i*2+1 и j*2 ≤ x ≤ j*2+1

Заб: може да не ползваме  const int&, a просто int
*/

float getMean(float** img, const int& imgRow, const int& imgCol,
	const int& startRow, const int& endRow,
	const int& startCol, const int& endCol) {
	float mean = 0.0f;
	int count = 0;

	for (int row = startRow; row < imgRow && row <= endRow; ++row) { // x
		for (int col = startCol; col < imgCol && col <= endCol; ++col) { // y
			mean += img[row][col];
			++count;
		}
	}

	return mean / count;
}

void subsample(const int& M, const int&  N, float** img) {
	const int ROW_SIZE = (M + 1) / 2;
	const int COL_SIZE = (N + 1) / 2;
	
	float** S = new float*[ROW_SIZE];
	for (int index = 0; index < ROW_SIZE; ++index) {
		S[index] = new float[COL_SIZE];
	}

	for (int row = 0; row < ROW_SIZE; ++row) {
		for (int col = 0; col < COL_SIZE; ++col) {
			S[row][col] = getMean(img, M, N, row * 2, row * 2 + 1, col * 2, col * 2 + 1);
		}
	}
}