import matplotlib.pyplot as plt
import numpy as np

tamanhos = [10, 100, 1000, 10000, 100000, 1000000]
insertion_sort = [0, 0, 0.001, 0.047, 0.396, 0.599]
selection_sort = [0, 0, 0, 0.360, 0.106, 0.285]
bubble_sort = [0, 0, 0, 0.001, 0.094, 0.090]
shell_sort = [0, 0, 0, 0.001, 0.003, 0.040]


plt.figure(figsize=(12, 8))
plt.plot(tamanhos, insertion_sort , marker='o', linestyle='-', color='blue', linewidth=2, label='Insertion Sort')
plt.plot(tamanhos, selection_sort, marker='o', linestyle='-', color='purple', linewidth=2, label='Selection Sort')
plt.plot(tamanhos, bubble_sort, marker='o', linestyle='-', color='orange', linewidth=2, label='Bubble Sort')
plt.plot(tamanhos, shell_sort, marker='o', linestyle='-', color='green', linewidth=2, label='Shell Sort')


plt.xscale('log')
plt.yscale('linear')
plt.xlabel('Tamanho', fontsize=12)
plt.ylabel('Tempo (segundos)', fontsize=12)
plt.title('Comparação dos Algoritmos de Ordenação (decrescente)', fontsize=14)
plt.legend(loc='upper left', fontsize=10)
plt.grid(True, linestyle='--', alpha=0.7)

plt.ylim(0, 0.5)

plt.savefig("comparacao_ordenacao_ajustada.png", format="png", dpi=300)
plt.show()
