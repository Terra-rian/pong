#include "audio.hpp"

Audio::Audio() {
    trackPaths[0] = "resources/sounds/tracks/track_1.mp3";
    trackPaths[1] = "resources/sounds/tracks/track_2.mp3";
    trackPaths[2] = "resources/sounds/tracks/track_3.mp3";

    effectPaths[0] = "resources/sounds/effects/paddle_hit.wav";
    effectPaths[1] = "resources/sounds/effects/score_up.wav";
    effectPaths[2] = "resources/sounds/effects/speed_up.wav";

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
        LogFatal << "Audio system couldn't be initialized. Error: " << Mix_GetError() << "\n";

        printAudioDrivers();
        audioOpened = false;
    } else {
        LogInfo << "Audio system initialized.\n";
        audioOpened = true;

        loadTracks();
        loadEffects();
    }
}

Audio::~Audio() {
    if(audioOpened) {
        Mix_CloseAudio();
    }
}

void Audio::loadTracks() {
    for(size_t i = 0; i < tracks.size(); i++) {
        tracks[i] = Mix_LoadMUS(trackPaths[i].c_str());

        if(tracks[i] == nullptr) {
            LogFatal << "Loading the track " + trackPaths[i] + " has failed. Error: " << Mix_GetError() << "\n";
        }
    }
}

void Audio::loadEffects() {
    for(size_t i = 0; i < effects.size(); i++) {
        effects[i] = Mix_LoadWAV(effectPaths[i].c_str());

        if(effects[i] == nullptr) {
            LogFatal << "Loading the effect " + effectPaths[i] + " has failed. Error: " << Mix_GetError() << "\n";
        }
    }
}

void Audio::playEffect(EffectType gameEffect) {
    Mix_Chunk* effect = nullptr;

    switch(gameEffect) {
        case EffectType::PADDLE_HIT:
            effect = effects[0];
            break;

        case EffectType::SCORE_UP:
            effect = effects[1];
            break;

        case EffectType::BALL_SPEED_UP:
            effect = effects[2];
            break;

        default:
            LogWarning << "This shouldn't have been reached, possible null game effect resource.\n";
            break;
    }

    Mix_VolumeMusic(64);

    if(Mix_PlayChannel(-1, effect, 0) == -1) {
        LogFatal << "Couldn't play an effect. Error: " << Mix_GetError() << "\n";
    }
}

void Audio::playMusic(Music musicTrack, const int& loops) {
    Mix_Music* music = nullptr;

    switch(musicTrack) {
        case Music::TRACK_1:
            music = tracks[0];
            break;

        case Music::TRACK_2:
            music = tracks[1];
            break;

        case Music::TRACK_3:
            music = tracks[2];
            break;

        default:
            LogWarning << "This shouldn't have been reached, possible null music track resource.\n";
            break;
    }

    if(Mix_PlayMusic(music, loops) == -1) {
        LogFatal << "Cannot play a track. Error: " << Mix_GetError() << "\n";
    }
}

bool Audio::isAudioOpen() const {
    return audioOpened;
}

void Audio::printAudioDrivers() {
    LogInfo << "System audio drivers available:\n";

    for(int i = 0; i < SDL_GetNumAudioDrivers(); i++) {
        LogInfo << "Available on index " << i << ": " << SDL_GetAudioDriver(i) << "\n";
    }
}