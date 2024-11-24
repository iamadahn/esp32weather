#ifndef FORECAST_JSON_H_
#define FORECAST_JSON_H_

#include <zephyr/data/json.h>

struct current_units {
    const char* time;
    const char* interval;
    const char* temperature_2m;
    const char* relative_humidity_2m;
    const char* apparent_temperature;
    const char* precipitation;

    /* if only it could cleanse the corrupt source of this world */
    const char* rain; 

    const char* weather_code;
    const char* wind_speed_10m;
};

struct current {
    const char* time;
    int interval;
    float temperature_2m;
    int relative_humidity_2m;
    float apparent_temperature;
    int precipitation;

    /* won't repeat my?self */
    int rain;

    int weather_code;
    float wind_speed_10m;
};

struct daily_units {
    const char* time;
    const char* temperature_2m_max;
    const char* temperature_2m_min;
    const char* apparent_temperature_max;
    const char* apparent_temperature_min;
};

struct daily {
    const char time;
    float temperature_2m_max;
    float temperature_2m_min;
    float apparent_temperature_max;
    float apparent_temperature_min;
};

struct forecast_data {
    float latitude;
    float longitude;
    float generationtime_ms;
    int utc_offset_seconds;
    const char* timezone; 
    const char* timezone_abbreviation;
    int elevation;
    struct current_units current_units;
    struct current current;
    struct daily_units daily_units;
    struct daily daily;
};

const struct json_obj_descr current_units_descr[] = {
    JSON_OBJ_DESCR_PRIM(struct current_units, time, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current_units, interval, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current_units, temperature_2m, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current_units, relative_humidity_2m, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current_units, apparent_temperature, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current_units, precipitation, JSON_TOK_STRING), 
    JSON_OBJ_DESCR_PRIM(struct current_units, rain, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current_units, weather_code, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current_units, wind_speed_10m, JSON_TOK_STRING),
};

const struct json_obj_descr current_descr[] = {
    JSON_OBJ_DESCR_PRIM(struct current, time, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct current, interval, JSON_TOK_NUMBER),
    JSON_OBJ_DESCR_PRIM(struct current, temperature_2m, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct current, relative_humidity_2m, JSON_TOK_NUMBER),
    JSON_OBJ_DESCR_PRIM(struct current, apparent_temperature, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct current, precipitation, JSON_TOK_NUMBER),
    JSON_OBJ_DESCR_PRIM(struct current, rain, JSON_TOK_NUMBER),
    JSON_OBJ_DESCR_PRIM(struct current, weather_code, JSON_TOK_NUMBER),
    JSON_OBJ_DESCR_PRIM(struct current, wind_speed_10m, JSON_TOK_FLOAT),
};

const struct json_obj_descr daily_units_descr[] = {
    JSON_OBJ_DESCR_PRIM(struct daily_units, time, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct daily_units, temperature_2m_max, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct daily_units, temperature_2m_min, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct daily_units, apparent_temperature_max, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct daily_units, apparent_temperature_min, JSON_TOK_STRING),
};

const struct json_obj_descr daily_descr[] = {
    JSON_OBJ_DESCR_PRIM(struct daily, time, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct daily, temperature_2m_max, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct daily, temperature_2m_min, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct daily, apparent_temperature_max, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct daily, apparent_temperature_min, JSON_TOK_FLOAT),

};

const struct json_obj_descr forecast_data_descr[] = {
    JSON_OBJ_DESCR_PRIM(struct forecast_data, latitude, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct forecast_data, longitude, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct forecast_data, generationtime_ms, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_PRIM(struct forecast_data, utc_offset_seconds, JSON_TOK_NUMBER),
    JSON_OBJ_DESCR_PRIM(struct forecast_data, timezone, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct forecast_data, timezone_abbreviation, JSON_TOK_STRING),
    JSON_OBJ_DESCR_PRIM(struct forecast_data, elevation, JSON_TOK_FLOAT),
    JSON_OBJ_DESCR_OBJECT(struct forecast_data, current_units, current_units_descr),
    JSON_OBJ_DESCR_OBJECT(struct forecast_data, current, current_descr),
    JSON_OBJ_DESCR_OBJECT(struct forecast_data, daily_units, daily_units_descr),
    JSON_OBJ_DESCR_OBJECT(struct forecast_data, daily, daily_descr),
};

#endif
