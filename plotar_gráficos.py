import matplotlib.pyplot as plt
import numpy as np

tamanhos = [10, 100, 1000, 10000, 100000, 1000000]
merge_sort = [0, 0, 0, 0.004, 0.018, 0.209]
quick_sort_primeiroElemento = [0, 0, 0, 0.001, 0.010, 0.117]  # Valores ajustados
quick_sort_media = [0, 0, 0, 0.002, 0.014, 0.145]
quick_sort_random = [0, 0, 0, 0.001, 0.011, 0.133]

plt.figure(figsize=(12, 8))
plt.plot(tamanhos, merge_sort, marker='o', linestyle='-', color='blue', linewidth=2, label='Merge Sort')
plt.plot(tamanhos, quick_sort_primeiroElemento, marker='o', linestyle='-', color='purple', linewidth=2, label='Quick Sort (Primeiro Elemento)')
plt.plot(tamanhos, quick_sort_media, marker='o', linestyle='-', color='orange', linewidth=2, label='Quick Sort (Média)')
plt.plot(tamanhos, quick_sort_random, marker='o', linestyle='-', color='green', linewidth=2, label='Quick Sort (Random)')

plt.xscale('log')
plt.yscale('linear')
plt.xlabel('Tamanho', fontsize=12)
plt.ylabel('Tempo (segundos)', fontsize=12)
plt.title('Comparação dos Algoritmos de Ordenação (aleatório)', fontsize=14)
plt.legend(loc='upper left', fontsize=10)
plt.grid(True, linestyle='--', alpha=0.7)

plt.ylim(0, 0.2)

plt.savefig("comparacao_ordenacao_ajustada.png", format="png", dpi=300)
plt.show()
