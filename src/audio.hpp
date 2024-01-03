#pragma once

#include "globals.hpp"

/**
 * @brief Wrapper class for `SDL2_mixer`, controls music tracks for the game.
 */
class Audio {
    public:
    /**
     * @brief Enum for all game effects.
     */
    enum class EffectType {
        PADDLE_HIT,
        SCORE_UP,
        BALL_SPEED_UP
    };

    /**
     * @brief Enum for all music tracks.
     */
    enum class Music {
        TRACK_1,
        TRACK_2,
        TRACK_3
    };

    /**
     * @brief Constructs a new `Audio` object.
     */
    Audio();

    /**
     * @brief Destructor for an `Audio` object.
     */
    ~Audio();

    /**
     * @brief Checks if an audio file is currently open.
     */
    bool isAudioOpen() const;

    /**
     * @brief Plays a music track.
     * @param musicTrack The music track to play.
     * @param loops The number of loops to play the music track for.
     */
    void playMusic(Music musicTrack, const int& loops);

    /**
     * @brief Plays a game effect.
     * @param gameEffect The game effect to play.
     */
    void playEffect(EffectType gameEffect);

    /**
     * @brief Lists all system audio drivers that are available.
     */
    void printAudioDrivers();

    private:
    /**
     * @brief Is the audio file open?
     */
    bool audioOpened;

    /**
     * @brief An array of game effects.
     */
    std::array<Mix_Chunk*, 3> effects;

    /**
     * @brief An array of game music tracks.
     */
    std::array<Mix_Music*, 3> tracks;

    /**
     * @brief An array of game effect paths.
     */
    std::array<std::string, 3> effectPaths;

    /**
     * @brief An array of game music track paths.
     */
    std::array<std::string, 3> trackPaths;

    /**
     * @brief Loads all music tracks.
     */
    void loadTracks();

    /**
     * @brief Loads all game effects.
     */
    void loadEffects();
};