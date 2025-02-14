# **Merge-sort** 

## Принцип работы: 
Алгоритм использует принцип «разделяй и властвуй»: задача разбивается на подзадачи меньшего размера, которые решаются по отдельности, после чего их решения комбинируются для получения решения исходной задачи. Конкретно процедуру сортировки слиянием можно описать следующим образом:

Если в рассматриваемом массиве один элемент, то он уже отсортирован — алгоритм завершает работу.
Иначе массив разбивается на две части, которые сортируются рекурсивно.
После сортировки двух частей массива к ним применяется процедура слияния, которая по двум отсортированным частям получает исходный отсортированный массив.

<img width="683" alt="мерджасимпт" src="https://github.com/user-attachments/assets/8f7729b1-96aa-4f9d-b55c-7946d8bf6207" />
