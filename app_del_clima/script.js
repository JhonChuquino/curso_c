// Obtener referencias a los elementos del DOM
const cityInput = document.getElementById('cityInput');
const getWeatherBtn = document.getElementById('getWeatherBtn');
const getForecastBtn = document.getElementById('getForecastBtn');
const weatherInfo = document.getElementById('weatherInfo');
const forecastContainer = document.getElementById('forecastContainer');

// Variable que indica si se está mostrando el clima actual o el pronóstico
let mostrandoClimaActual = true;

function mostrarClimaActual(datos) {
    // Generar el HTML para mostrar la información del clima actual
    const weatherInfoHTML = `
    <div class="weather-grid">
        <div class="weather-item">
            <img src="temperatura.png" alt="Temperatura">
            <p>Temperatura actual: ${datos.main.temp} °C</p>
        </div>
        <div class="weather-item">
            <img src="max_temp.png" alt="Temperatura Máxima">
            <p>Temperatura máxima: ${datos.main.temp_max} °C</p>
        </div>
        <div class="weather-item">
            <img src="min_temp.png" alt="Temperatura Mínima">
            <p>Temperatura mínima: ${datos.main.temp_min} °C</p>
        </div>
        <div class="weather-item">
            <img src="presion.png" alt="Presión">
            <p>Presión: ${datos.main.pressure} hPa</p>
        </div>
        <div class="weather-item">
            <img src="humedad.png" alt="Humedad">
            <p>Humedad: ${datos.main.humidity}%</p>
        </div>
        <div class="weather-item">
            <img src="velocidad_viento.png" alt="Velocidad del Viento">
            <p>Velocidad del viento: ${datos.wind.speed} m/s</p>
        </div>
    </div>
    `;
    // Insertar el HTML en el elemento weatherInfo y mostrarlo
    weatherInfo.innerHTML = weatherInfoHTML;
    weatherInfo.style.display = 'block';

    // Mostrar el botón de pronóstico después de obtener los datos del clima actual
    getForecastBtn.style.display = 'block';
    mostrandoClimaActual = true;
}

function mostrarPronostico(pronostico) {
    
    forecastContainer.innerHTML = ''; // Limpiar el contenido del contenedor antes de mostrar el pronóstico
    //Generar HTML para cada día del pronostico
    let filaHTML = '<div class="forecast-row">';

    pronostico.forEach(dia => {
        //Obtener detalles del pronostico para cada dia
        const fechaHora = new Date(dia.dt_txt);
        const fechaFormato = formatoFecha(fechaHora);
        const tempMax = dia.main.temp_max;
        const tempMin = dia.main.temp_min;
        const presion = dia.main.pressure;
        const humedad = dia.main.humidity;
        const velocidadViento = dia.wind.speed;
        //Generar HTML para mostrar los detalles del pronostico
        const pronosticoItemHTML = `
            <div class="forecast-item">
                <p class="fecha-hora">${formatoFechaHora(fechaHora)}</p>
                <img src="temperatura.png" alt="Temperatura Máxima">
                <p>Temp Máx: ${tempMax} °C</p>
                <img src="temperatura.png" alt="Temperatura Mínima">
                <p>Temp Mín: ${tempMin} °C</p>
                <img src="presion.png" alt="Presión">
                <p>Presión: ${presion} hPa</p>
                <img src="humedad.png" alt="Humedad">
                <p>Humedad: ${humedad}%</p>
                <img src="velocidad_viento.png" alt="Velocidad del Viento">
                <p>Viento: ${velocidadViento} m/s</p>
            </div>
        `;
        //Insertar el HTML en el contenedor del pronóstico
        forecastContainer.insertAdjacentHTML('beforeend', pronosticoItemHTML);
    });
    //Insertar la filaHTML con los dias del pronostico
    if (filaHTML !== '') {
        forecastContainer.insertAdjacentHTML('beforeend', `<div class="forecast-grid">${filaHTML}</div>`);
    }
    //Mostrar el contenedor
    forecastContainer.style.display = 'block'; // Mostrar el contenedor del pronóstico
    mostrandoClimaActual = false;
}
//formatear la fecha
function formatoFecha(fecha) {
    const opciones = { year: 'numeric', month: 'long', day: 'numeric' };
    return new Intl.DateTimeFormat('es-ES', opciones).format(fecha);
}
//formatear fecha y hora
function formatoFechaHora(fecha) {
    const opciones = { year: 'numeric', month: 'long', day: 'numeric', hour: 'numeric', minute: 'numeric', hour12: true };
    return new Intl.DateTimeFormat('es-ES', opciones).format(fecha);
}

//Ocultar el clima actual
function ocultarClimaActual() {
    weatherInfo.style.display = 'none';
}
//Ocultar los pronosticos
function ocultarPronostico() {
    forecastContainer.style.display = 'none'; // Usar forecastContainer en lugar de pronosticoContainer
}
// Agregar evento click al botón "Ver Clima Actual"
getWeatherBtn.addEventListener('click', () => {
    // Obtener ciudad ingresada por el usuario
    const city = cityInput.value;
    //Usamos el api 
    const api_key = '083a9058653cf5ba121f7cba5d9a1526';
    const apiUrl = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${api_key}&units=metric`;
    //Realizamos la solicitud a la API y mostramos los datos
    fetch(apiUrl)
        .then(response => response.json())
        .then(data => {
            ocultarPronostico(); // Ocultar el pronóstico al mostrar los datos actuales
            mostrarClimaActual(data);
        })
        .catch(error => {
            console.error('Error al obtener los datos del clima:', error);
        });
});

getForecastBtn.addEventListener('click', () => {
    const city = cityInput.value;
    const api_key = '083a9058653cf5ba121f7cba5d9a1526';
    obtenerPronostico(city, api_key);
    ocultarClimaActual();
});

function obtenerPronostico(ciudad, api_key) {
    //construir URL de la API para los pronosticos
    const apiUrl = `https://api.openweathermap.org/data/2.5/forecast?q=${ciudad}&appid=${api_key}&units=metric`;

    fetch(apiUrl)
        .then(response => response.json())
        .then(pronostico => {
            mostrarPronostico(pronostico.list);
        })
        .catch(error => {
            console.error('Error al obtener el pronóstico del clima:', error);
        });
}

// Función para analizar las tendencias en el pronóstico
function analizarTendencias(pronostico) {
    // Inicializar variables para almacenar tendencias
    let tendenciaPresion = '';
    let tendenciaHumedad = '';
    let tendenciaViento = '';

    // Analizar tendencias en base a los valores del pronóstico
    for (let i = 1; i < pronostico.length; i++) {
        const presionActual = pronostico[i].main.pressure;
        const presionAnterior = pronostico[i - 1].main.pressure;
        if (presionActual > presionAnterior) {
            tendenciaPresion = 'Aumentando';
        } else if (presionActual < presionAnterior) {
            tendenciaPresion = 'Disminuyendo';
        }

        const humedadActual = pronostico[i].main.humidity;
        const humedadAnterior = pronostico[i - 1].main.humidity;
        if (humedadActual > humedadAnterior) {
            tendenciaHumedad = 'Aumentando';
        } else if (humedadActual < humedadAnterior) {
            tendenciaHumedad = 'Disminuyendo';
        }

        const vientoActual = pronostico[i].wind.speed;
        const vientoAnterior = pronostico[i - 1].wind.speed;
        if (vientoActual > vientoAnterior) {
            tendenciaViento = 'Aumentando';
        } else if (vientoActual < vientoAnterior) {
            tendenciaViento = 'Disminuyendo';
        }
    }

    // Generar HTML para mostrar las tendencias
    const tendenciasHTML = `
        <div class="tendencias">
            <h2>Tendencias en el Pronóstico</h2>
            <p>Presión: ${tendenciaPresion}</p>
            <p>Humedad: ${tendenciaHumedad}</p>
            <p>Viento: ${tendenciaViento}</p>
        </div>
    `;

    // Insertar el HTML en el contenedor de pronóstico
    forecastContainer.insertAdjacentHTML('beforeend', tendenciasHTML);
    
}


