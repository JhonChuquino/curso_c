import pandas as pd
import random
import tensorflow as tf
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error, r2_score
from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error, r2_score
from sklearn.svm import SVR
from sklearn.ensemble import RandomForestRegressor

# Cargar tus datos en el DataFrame 'df'
ruta = "E:\\E. Datos y Algoritmos\\app_del_clima\\Datos Historicos\\datos_entrenamiento.csv"
df = pd.read_csv(ruta, sep=';')

# Eliminar columnas no relevantes para el modelo (si es necesario)
columnas_no_relevantes = ['Año', 'Mes', 'Dia', 'Precipitacion', 'O3']  # O3 se considera no relevante
df = df.drop(columns=columnas_no_relevantes)

# Asegurarse de mantener al menos una columna relevante en X_train
columnas_relevantes = ['Tmaxima', 'Tminima']  # Conservamos estas columnas

# Eliminar filas con valores extremadamente bajos (-99)
df = df[(df['Tmaxima'] != -99) & (df['Tminima'] != -99)]

# Escalar las características para normalizarlas
scaler = StandardScaler()
X_scaled = scaler.fit_transform(df[columnas_relevantes].values)
y = df[columnas_relevantes].values

# Dividir los datos en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

# Define modelos separados para Tmaxima y Tminima
model_Tmaxima = tf.keras.Sequential([
    tf.keras.layers.Conv1D(64, 2, activation='relu', input_shape=(X_train.shape[1], 1)),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(units=128, activation='relu'),
    tf.keras.layers.Dropout(0.5),
    tf.keras.layers.Dense(units=64, activation='relu'),
    tf.keras.layers.Dropout(0.3),
    tf.keras.layers.Dense(units=32, activation='relu'),
    tf.keras.layers.Dense(units=1)
])

model_Tminima = tf.keras.Sequential([
    tf.keras.layers.Conv1D(64, 2, activation='relu', input_shape=(X_train.shape[1], 1)),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(units=128, activation='relu'),
    tf.keras.layers.Dropout(0.5),
    tf.keras.layers.Dense(units=64, activation='relu'),
    tf.keras.layers.Dropout(0.3),
    tf.keras.layers.Dense(units=32, activation='relu'),
    tf.keras.layers.Dense(units=1)
])

# Compilar los modelos
model_Tmaxima.compile(optimizer='adam', loss='mean_squared_error')
model_Tminima.compile(optimizer='adam', loss='mean_squared_error')

# Entrenar los modelos
history_Tmaxima = model_Tmaxima.fit(X_train, y_train[:, 0], epochs=100, batch_size=64, validation_split=0.2, verbose=1)
history_Tminima = model_Tminima.fit(X_train, y_train[:, 1], epochs=100, batch_size=64, validation_split=0.2, verbose=1)

# Evaluar los modelos en los datos de prueba
y_pred_Tmaxima = model_Tmaxima.predict(X_test)
y_pred_Tminima = model_Tminima.predict(X_test)

mae_Tmaxima = mean_absolute_error(y_test[:, 0], y_pred_Tmaxima)
mse_Tmaxima = mean_squared_error(y_test[:, 0], y_pred_Tmaxima)
mape_Tmaxima = mean_absolute_percentage_error(y_test[:, 0], y_pred_Tmaxima)
r2_Tmaxima = r2_score(y_test[:, 0], y_pred_Tmaxima)

mae_Tminima = mean_absolute_error(y_test[:, 1], y_pred_Tminima)
mse_Tminima = mean_squared_error(y_test[:, 1], y_pred_Tminima)
mape_Tminima = mean_absolute_percentage_error(y_test[:, 1], y_pred_Tminima)
r2_Tminima = r2_score(y_test[:, 1], y_pred_Tminima)

print('Tmaxima (Red Neuronal):')
print('Error absoluto medio (MAE) Red Neuronal:', mae_Tmaxima)
print('Error cuadrado medio (MSE) Red Neuronal:', mse_Tmaxima)
print('Error porcentual absoluto medio (MAPE) Red Neuronal:', mape_Tmaxima)
print('Coeficiente de determinación (R-squared) Red Neuronal:', r2_Tmaxima)

print('Tminima (Red Neuronal):')
print('Error absoluto medio (MAE) Red Neuronal:', mae_Tminima)
print('Error cuadrado medio (MSE) Red Neuronal:', mse_Tminima)
print('Error porcentual absoluto medio (MAPE) Red Neuronal:', mape_Tminima)
print('Coeficiente de determinación (R-squared) Red Neuronal:', r2_Tminima)

# Modelo SVM
model_SVM_Tmaxima = SVR()
model_SVM_Tminima = SVR()

model_SVM_Tmaxima.fit(X_train, y_train[:, 0])
model_SVM_Tminima.fit(X_train, y_train[:, 1])

y_pred_SVM_Tmaxima = model_SVM_Tmaxima.predict(X_test)
y_pred_SVM_Tminima = model_SVM_Tminima.predict(X_test)

mae_SVM_Tmaxima = mean_absolute_error(y_test[:, 0], y_pred_SVM_Tmaxima)
mse_SVM_Tmaxima = mean_squared_error(y_test[:, 0], y_pred_SVM_Tmaxima)
mape_SVM_Tmaxima = mean_absolute_percentage_error(y_test[:, 0], y_pred_SVM_Tmaxima)
r2_SVM_Tmaxima = r2_score(y_test[:, 0], y_pred_SVM_Tmaxima)

mae_SVM_Tminima = mean_absolute_error(y_test[:, 1], y_pred_SVM_Tminima)
mse_SVM_Tminima = mean_squared_error(y_test[:, 1], y_pred_SVM_Tminima)
mape_SVM_Tminima = mean_absolute_percentage_error(y_test[:, 1], y_pred_SVM_Tminima)
r2_SVM_Tminima = r2_score(y_test[:, 1], y_pred_SVM_Tminima)

print('Tmaxima (SVM):')
print('Error absoluto medio (MAE) SVM:', mae_SVM_Tmaxima)
print('Error cuadrado medio (MSE) SVM:', mse_SVM_Tmaxima)
print('Error porcentual absoluto medio (MAPE) SVM:', mape_SVM_Tmaxima)
print('Coeficiente de determinación (R-squared) SVM:', r2_SVM_Tmaxima)

print('Tminima (SVM):')
print('Error absoluto medio (MAE) SVM:', mae_SVM_Tminima)
print('Error cuadrado medio (MSE) SVM:', mse_SVM_Tminima)
print('Error porcentual absoluto medio (MAPE) SVM:', mape_SVM_Tminima)
print('Coeficiente de determinación (R-squared) SVM:', r2_SVM_Tminima)

# Modelo Random Forest
model_RF_Tmaxima = RandomForestRegressor()
model_RF_Tminima = RandomForestRegressor()

model_RF_Tmaxima.fit(X_train, y_train[:, 0])
model_RF_Tminima.fit(X_train, y_train[:, 1])

y_pred_RF_Tmaxima = model_RF_Tmaxima.predict(X_test)
y_pred_RF_Tminima = model_RF_Tminima.predict(X_test)

mae_RF_Tmaxima = mean_absolute_error(y_test[:, 0], y_pred_RF_Tmaxima)
mse_RF_Tmaxima = mean_squared_error(y_test[:, 0], y_pred_RF_Tmaxima)
mape_RF_Tmaxima = mean_absolute_percentage_error(y_test[:, 0], y_pred_RF_Tmaxima)
r2_RF_Tmaxima = r2_score(y_test[:, 0], y_pred_RF_Tmaxima)

mae_RF_Tminima = mean_absolute_error(y_test[:, 1], y_pred_RF_Tminima)
mse_RF_Tminima = mean_squared_error(y_test[:, 1], y_pred_RF_Tminima)
mape_RF_Tminima = mean_absolute_percentage_error(y_test[:, 1], y_pred_RF_Tminima)
r2_RF_Tminima = r2_score(y_test[:, 1], y_pred_RF_Tminima)

print('Tmaxima (Random Forest):')
print('Error absoluto medio (MAE) Random Forest:', mae_RF_Tmaxima)
print('Error cuadrado medio (MSE) Random Forest:', mse_RF_Tmaxima)
print('Error porcentual absoluto medio (MAPE) Random Forest:', mape_RF_Tmaxima)
print('Coeficiente de determinación (R-squared) Random Forest:', r2_RF_Tmaxima)

print('Tminima (Random Forest):')
print('Error absoluto medio (MAE) Random Forest:', mae_RF_Tminima)
print('Error cuadrado medio (MSE) Random Forest:', mse_RF_Tminima)
print('Error porcentual absoluto medio (MAPE) Random Forest:', mape_RF_Tminima)
print('Coeficiente de determinación (R-squared) Random Forest:', r2_RF_Tminima)

# Visualización de Resultados para Tmaxima
plt.figure(figsize=(12, 6))
plt.plot(y_test[:, 0], label='Tmaxima Real', marker='o')
plt.plot(y_pred_Tmaxima, label='Tmaxima Predicha', marker='x')
plt.xlabel('Índice de Tiempo')
plt.ylabel('Tmaxima')
plt.title('Predicción de Tmaxima vs. Real')
plt.legend()
plt.show()

# Visualización de Resultados para Tminima
plt.figure(figsize=(12, 6))
plt.plot(y_test[:, 1], label='Tminima Real', marker='o')
plt.plot(y_pred_Tminima, label='Tminima Predicha', marker='x')
plt.xlabel('Índice de Tiempo')
plt.ylabel('Tminima')
plt.title('Predicción de Tminima vs. Real')
plt.legend()
plt.show()


# Supongamos que deseas hacer predicciones para septiembre de 2023
tmaxima_prediccion = 36
tminima_prediccion = 22

# Supongamos que deseas hacer predicciones para septiembre de 2023
# Crea una lista de fechas para septiembre de 2023
fechas_septiembre = pd.date_range(start='01-09-2023', end='30-09-2023', freq='D')

# Crea un DataFrame para almacenar las predicciones
predicciones_df = pd.DataFrame(columns=['Fecha', 'Tmaxima', 'Tminima'])

for fecha in fechas_septiembre:
    # Genera valores aleatorios para tmaxima_prediccion y tminima_prediccion
    tmaxima_prediccion = random.uniform(25, 35)  # Ejemplo: valores entre 25 y 35 grados Celsius
    tminima_prediccion = random.uniform(20, 25)  # Ejemplo: valores entre 15 y 25 grados Celsius

    # Realiza la predicción para Tmaxima y Tminima
    fecha_entrada = scaler.transform([[tmaxima_prediccion, tminima_prediccion]])
    prediccion_final_Tmaxima = model_Tmaxima.predict(fecha_entrada)
    prediccion_final_Tminima = model_Tminima.predict(fecha_entrada)
    
    # Agrega la predicción al DataFrame de predicciones utilizando .loc
    predicciones_df.loc[len(predicciones_df)] = [fecha, prediccion_final_Tmaxima[0], prediccion_final_Tminima[0]]

# Guarda las predicciones en un archivo CSV
predicciones_df.to_csv('E:\\E. Datos y Algoritmos\\app_del_clima\\Datos Historicos\\predicciones_mes.csv', index=False)

