import matplotlib.pyplot as plt
import pandas as pd

# READ CSV FILE
df = pd.read_csv("../results.csv")

df.columns = df.columns.str.strip()

# Pivot Table: rows = n, columns = Algorithm, values = Time
pivot_df = df.pivot(index='n', columns='Algorithm', values='Time')

# Plot
pivot_df.plot(marker='o', figsize=(10, 6))
plt.title("Sorting Algorithm Performance")
plt.xlabel("Input Size (n)")
plt.yscale('log')
plt.ylabel("Time (seconds, log scale)")
plt.grid(True)
plt.legend(title="Algorithm")
plt.tight_layout()
plt.show()
