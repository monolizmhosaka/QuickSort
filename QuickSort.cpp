// QuickSort.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

void q_sort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        // 右からpivotよりも小さいが値があるか走査
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }

        // 左からpivotよりも小さいが値があるか走査
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    // 分割したそれぞれの範囲を呼び出す準備
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;

    // ２つに分けたものをソートで再帰呼び出し
    if (left < pivot)
        q_sort(numbers, left, pivot - 1);
    if (right > pivot)
        q_sort(numbers, pivot + 1, right);
}


void printArray(int numbers[], int array_size)
{
    int x = 0;
    for (x = 0; x < array_size; x++) {
        printf("%d ", numbers[x]);
    }
}

void quickSort(int numbers[], int array_size)
{
    q_sort(numbers, 0, array_size - 1);
}


int main()
{
    int numbers[] = { 3,1,8,7,6};
    const int ArrSize = sizeof numbers / sizeof numbers[0];

    printf("Start: ");
    printArray(numbers, ArrSize);
    printf("\n");

    //クリックソート
    quickSort(numbers, ArrSize);

    printf("Done with sort.\n");
    printArray(numbers, ArrSize);
    printf("\n");

    return 0;
}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
