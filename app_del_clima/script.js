document.addEventListener('DOMContentLoaded', function() {
    // Obtener referencias a los elementos del DOM
    const cityInput = document.getElementById('cityInput');
    const getWeatherBtn = document.getElementById('getWeatherBtn');
    const getForecastBtn = document.getElementById('getForecastBtn');
    const weatherInfo = document.getElementById('weatherInfo');
    const forecastContainer = document.getElementById('forecastContainer');
    const btnVerCalidadAire = document.getElementById("btnVerCalidadAire");

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

    function mostrarPronóstico(pronóstico) {
        forecastContainer.innerHTML = ''; // Limpiar el contenido del contenedor antes de mostrar el pronóstico
        // Generar HTML para cada día del pronóstico
        let filaHTML = '<div class="forecast-row">';

        pronóstico.forEach(día => {
            // Obtener detalles del pronóstico para cada día
            const fechaHora = new Date(día.dt_txt);
            const fechaFormato = formatoFecha(fechaHora);
            const tempMax = día.main.temp_max;
            const tempMin = día.main.temp_min;
            const presión = día.main.pressure;
            const humedad = día.main.humidity;
            const velocidadViento = día.wind.speed;
            // Generar HTML para mostrar los detalles del pronóstico
            const pronósticoItemHTML = `
                <div class="forecast-item">
                    <p class="fecha-hora">${formatoFechaHora(fechaHora)}</p>
                    <img src="temperatura.png" alt="Temperatura Máxima">
                    <p>Temp Máx: ${tempMax} °C</p>
                    <img src="temperatura.png" alt="Temperatura Mínima">
                    <p>Temp Mín: ${tempMin} °C</p>
                    <img src="presion.png" alt="Presión">
                    <p>Presión: ${presión} hPa</p>
                    <img src="humedad.png" alt="Humedad">
                    <p>Humedad: ${humedad}%</p>
                    <img src="velocidad_viento.png" alt="Velocidad del Viento">
                    <p>Viento: ${velocidadViento} m/s</p>
                </div>
            `;
            // Insertar el HTML en el contenedor del pronóstico
            forecastContainer.insertAdjacentHTML('beforeend', pronósticoItemHTML);
        });
        // Insertar la fila HTML con los días del pronóstico
        if (filaHTML !== '') {
            forecastContainer.insertAdjacentHTML('beforeend', `<div class="forecast-grid">${filaHTML}</div>`);
        }
        // Mostrar el contenedor
        forecastContainer.style.display = 'block'; // Mostrar el contenedor del pronóstico
        mostrandoClimaActual = false;
    }

    // Formatear la fecha
    function formatoFecha(fecha) {
        const opciones = { year: 'numeric', month: 'long', day: 'numeric' };
        return new Intl.DateTimeFormat('es-ES', opciones).format(fecha);
    }

    // Formatear fecha y hora
    function formatoFechaHora(fecha) {
        const opciones = { year: 'numeric', month: 'long', day: 'numeric', hour: 'numeric', minute: 'numeric', hour12: true };
        return new Intl.DateTimeFormat('es-ES', opciones).format(fecha);
    }

    // Ocultar el clima actual
    function ocultarClimaActual() {
        weatherInfo.style.display = 'none';
    }

    // Ocultar el pronóstico
    function ocultarPronóstico() {
        forecastContainer.style.display = 'none';
    }

    // Agregar evento click al botón "Ver Clima Actual"
    getWeatherBtn.addEventListener('click', () => {
        // Obtener ciudad ingresada por el usuario
        const city = cityInput.value;
        // Usamos el API
        const api_key = '083a9058653cf5ba121f7cba5d9a1526';
        const apiUrl = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${api_key}&units=metric`;
        // Realizamos la solicitud a la API y mostramos los datos
        fetch(apiUrl)
            .then(response => response.json())
            .then(data => {
                ocultarPronóstico(); // Ocultar el pronóstico al mostrar los datos actuales
                mostrarClimaActual(data);
            })
            .catch(error => {
                console.error('Error al obtener los datos del clima:', error);
            });
    });

    getForecastBtn.addEventListener('click', () => {
        const city = cityInput.value;
        const api_key = '083a9058653cf5ba121f7cba5d9a1526';
        obtenerPronóstico(city, api_key);
        ocultarClimaActual();
    });

    function obtenerPronóstico(ciudad, api_key) {
        // Construir URL de la API para los pronósticos
        const apiUrl = `https://api.openweathermap.org/data/2.5/forecast?q=${ciudad}&appid=${api_key}&units=metric`;

        fetch(apiUrl)
            .then(response => response.json())
            .then(pronóstico => {
                mostrarPronóstico(pronóstico.list);
            })
            .catch(error => {
                console.error('Error al obtener el pronóstico del clima:', error);
            });
    }
});
