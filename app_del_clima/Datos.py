import pandas as pd
import matplotlib.pyplot as plt

# Cargar los datos desde los archivos CSV, especificando el delimitador como punto y coma
df_neuronal = pd.read_csv('E:\\E. Datos y Algoritmos\\app_del_clima\\Datos Historicos\\predicciones_mes.csv', delimiter=';')
df_app_clima = pd.read_csv('E:\\E. Datos y Algoritmos\\app_del_clima\\Datos Historicos\\predicciones_app.csv', delimiter=';')
df_datos_reales = pd.read_csv('E:\\E. Datos y Algoritmos\\app_del_clima\\Datos Historicos\\datos_reales.csv', delimiter=';')

# Seleccionar las columnas relevantes (Fecha, Tmaxima, Tminima)
df_neuronal = df_neuronal[['Fecha', 'Tmaxima', 'Tminima']]
df_app_clima = df_app_clima[['Fecha', 'Tmaxima', 'Tminima']]
df_datos_reales = df_datos_reales[['Fecha', 'Tmaxima', 'Tminima']]

# Combinar los datos en un solo DataFrame utilizando la columna de Fecha como índice
df_combined = df_neuronal.merge(df_app_clima, on='Fecha', suffixes=('_Neuronal', '_AppClima'))
df_combined = df_combined.merge(df_datos_reales, on='Fecha', suffixes=('', '_Reales'))

# Calcular métricas de comparación (puedes personalizar esto)
mae_neuronal_Tmaxima = abs(df_combined['Tmaxima_Neuronal'] - df_combined['Tmaxima']).mean()
mae_app_clima_Tmaxima = abs(df_combined['Tmaxima_AppClima'] - df_combined['Tmaxima']).mean()
mae_neuronal_Tminima = abs(df_combined['Tminima_Neuronal'] - df_combined['Tminima']).mean()
mae_app_clima_Tminima = abs(df_combined['Tminima_AppClima'] - df_combined['Tminima']).mean()

# Crear un gráfico con dos subplots para Tmaxima y Tminima
plt.figure(figsize=(12, 8))

# Subplot para Tmaxima
plt.subplot(2, 1, 1)
plt.plot(df_combined['Fecha'], df_combined['Tmaxima_Neuronal'], label='Tmaxima Neuronal', linestyle='-', marker='o')
plt.plot(df_combined['Fecha'], df_combined['Tmaxima_AppClima'], label='Tmaxima App Clima', linestyle='-', marker='x')
plt.plot(df_combined['Fecha'], df_combined['Tmaxima'], label='Tmaxima Datos Reales', linestyle='-', marker='s')
plt.xlabel('Fecha')
plt.ylabel('Tmaxima')
plt.title('Comparación de Tmaxima entre Neuronal, App Clima y Datos Reales')
plt.xticks(rotation=45, fontsize=8)  # Rotar etiquetas y ajustar tamaño de fuente
plt.legend()

# Subplot para Tminima
plt.subplot(2, 1, 2)
plt.plot(df_combined['Fecha'], df_combined['Tminima_Neuronal'], label='Tminima Neuronal', linestyle='-', marker='o')
plt.plot(df_combined['Fecha'], df_combined['Tminima_AppClima'], label='Tminima App Clima', linestyle='-', marker='x')
plt.plot(df_combined['Fecha'], df_combined['Tminima'], label='Tminima Datos Reales', linestyle='-', marker='s')
plt.xlabel('Fecha')
plt.ylabel('Tminima')
plt.title('Comparación de Tminima entre Neuronal, App Clima y Datos Reales')
plt.xticks(rotation=45, fontsize=8)  # Rotar etiquetas y ajustar tamaño de fuente
plt.legend()

# Ajustar el espacio entre los subplots
plt.tight_layout()

# Mostrar el gráfico
plt.show()

# Imprimir métricas de comparación
print(f'MAE Tmaxima Neuronal vs. Datos Reales: {mae_neuronal_Tmaxima:.2f}')
print(f'MAE Tmaxima App Clima vs. Datos Reales: {mae_app_clima_Tmaxima:.2f}')
print(f'MAE Tminima Neuronal vs. Datos Reales: {mae_neuronal_Tminima:.2f}')
print(f'MAE Tminima App Clima vs. Datos Reales: {mae_app_clima_Tminima:.2f}')