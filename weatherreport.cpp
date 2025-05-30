#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {
        int Humidity() const override {
            return 72;
        }

        int Precipitation() const override {
            return 70;
        }

        double TemperatureInC() const override {
            return 26;
        }

        int WindSpeedKMPH() const override {
            return 52;
        }
    };
    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (precipitation >= 60)
                report = "Alert, Stormy with heavy rain";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
    void TestHighTemperatureAndPrecipitation() {
        class HighTempHighPrecipSensor : public IWeatherSensor {
            int Humidity() const override { return 80; }
            int Precipitation() const override { return 70; }
            double TemperatureInC() const override { return 30; }
            int WindSpeedKMPH() const override { return 30; }
        };
        
        HighTempHighPrecipSensor sensor;
        string report = Report(sensor);
        assert(report.find("rain") != string::npos);
        cout << "High temperature and precipitation test passed!\n";
    }

    void TestHighTemperatureAndWind() {
        class HighTempHighWindSensor : public IWeatherSensor {
            int Humidity() const override { return 60; }
            int Precipitation() const override { return 30; }
            double TemperatureInC() const override { return 28; }
            int WindSpeedKMPH() const override { return 55; }
        };
        
        HighTempHighWindSensor sensor;
        string report = Report(sensor);
        assert(report.find("rain") != string::npos);
        cout << "High temperature and wind test passed!\n";
    }

    void TestSunnyDay() {
        class SunnySensorStub : public IWeatherSensor {
            int Humidity() const override { return 30; }
            int Precipitation() const override { return 10; }
            double TemperatureInC() const override { return 20; }
            int WindSpeedKMPH() const override { return 10; }
        };
        
        SunnySensorStub sensor;
        string report = Report(sensor);
        assert(report == "Sunny Day");
        cout << "Sunny day test passed!\n";
    }

    void TestPartlyCloudy() {
        class PartlyCloudySensorStub : public IWeatherSensor {
            int Humidity() const override { return 60; }
            int Precipitation() const override { return 40; }
            double TemperatureInC() const override { return 26; }
            int WindSpeedKMPH() const override { return 30; }
        };
        
        PartlyCloudySensorStub sensor;
        string report = Report(sensor);
        assert(report == "Partly Cloudy");
        cout << "Partly cloudy test passed!\n";
    }
}

void testWeatherReport() {
    cout << "\nWeather report test suite\n";
    WeatherSpace::TestHighTemperatureAndPrecipitation();
    WeatherSpace::TestHighTemperatureAndWind();
    WeatherSpace::TestSunnyDay();
    WeatherSpace::TestPartlyCloudy();
    cout << "All weather report tests passed!\n";
}
