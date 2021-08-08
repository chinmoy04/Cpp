#include <iostream>

using namespace std;

// WavParserLegacy.cpp : Defines the entry point for the console application.
//====================================================================================================
//
// Author: Narayan Iyer (narayaniyer.com)
// This is distributed as a part of Design Patterns training material
// NOT A PRODUCTION CODE - NO EXPLICIT OR IMPLIED WARRANTIES
// Use this file for any experimentation purpose copyright must not be removed
//====================================================================================================

#include "inttypes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/*****

The header of a WAV (RIFF) file is 44 bytes long and has the following format:
Positions 	Sample Value 	Description
1 - 4 	"RIFF" 	Marks the file as a riff file. Characters are each 1 byte long.
5 - 8 	File size (integer) 	Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you'd fill this in after creation.
9 -12 	"WAVE" 	File Type Header. For our purposes, it always equals "WAVE".
13-16 	"fmt " 	Format chunk marker. Includes trailing null
17-20 	16 	Length of format data as listed above
21-22 	1 	Type of format (1 is PCM) - 2 byte integer
23-24 	2 	Number of Channels - 2 byte integer
25-28 	44100 	Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.
29-32 	176400 	(Sample Rate * BitsPerSample * Channels) / 8.
33-34 	4 	(BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
35-36 	16 	Bits per sample
37-40 	"data" 	"data" chunk header. Marks the beginning of the data section.
41-44 	File size (data) 	Size of the data section.


****/

typedef struct
{
    uint32_t header_signature;  /* signature should be "RIFF" */
    uint32_t file_size; /* file size */
    uint32_t file_type; /*file type : "WAVE" */

    uint32_t fmt_chunk_signature; /*fmt chunk: "fmt" with null termination*/
    uint32_t fmt_length; /*fmt length*/

    uint16_t fmt_type; /*fmt type 1: PCM*/
    uint16_t no_of_channels; /*No of channels*/

    uint32_t sample_rate; /* Common values are 44100 (CD),
						  48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.*/
    uint32_t sample_byte_rate; /* 176400 	(Sample Rate * BitsPerSample * Channels) / 8. */

    uint16_t block_align; /* 4 	(BitsPerSample * Channels) / 8.1 - 8 bit mono2 -
						  8 bit stereo/16 bit mono4 - 16 bit stereo */
    uint16_t bits_per_sample; /* Bits per sample */

    uint32_t data_chunk_signature; /*data chunk: "data" */
    uint32_t data_length; /* File size (data) 	Size of the data section. */
} audio_file_header_t;

const uint8_t HEADER_LEN = 44; /* header length */
const uint8_t MAX_FILENAME_SIZE = 255; /* max file size */
const uint32_t RIFF_SIGNATURE = 0x46464952;
const uint8_t PCM_TYPE = 1;


class IOInterface
{
protected:
    string filename;
    string rwoptions;
public:
    IOInterface()
    {
        rwoptions = "r";
    }
    void setfilename(string& fname)
    {
        filename = fname;
    }
    void setrwoptions(string& rwopt)
    {
        rwoptions = rwopt;
    }
    virtual int open()=0;
    virtual int close()=0;
    virtual int read(char *rd_data, int
                     read_unit_size, int read_len)=0;
    virtual int write(const char *wr_data, int write_unit_size, int write_len)=0;
};


class IOFSImpl : public IOInterface
{
    FILE *fp;
    virtual int open()
    {
        fp = fopen(filename.c_str(), "r");

        if (fp == NULL)
        {
            printf("Unable to open file %s\n", filename.c_str());
            printf("press any key");
            fflush(stdin);
            getchar();

            return -1;
        }
        return 0;
    }
    virtual int close()
    {
        return fclose(fp);

    }
    virtual int read(char *rd_data, int  read_unit_size, int read_len)
    {
        size_t read_sz = fread(rd_data, sizeof(uint8_t), read_len, fp);

        if (read_sz != read_len)
        {
            printf("Unable to read header, file may be partially truncated: byte read  %d\n", read_sz);
            return -1;
        }

    }

    virtual int write(const char *wr_data, int write_unit_size, int write_len)
    {
        size_t wr_sz = fwrite(wr_data, sizeof(uint8_t), write_len, fp);

        if (wr_sz != write_len)
        {
            printf("Unable to write, file may be partially truncated: byte read  %d\n", write_len);
            return -1;
        }

        return -1;
    }


};



class WavParser
{
public:

    IOInterface *pio;
    WavParser(IOInterface *_pio)
    {
        pio = _pio;
    }

    int accept_file_name(char *szfilename)
    {
        printf("Enter filename to be read:");
        scanf("%s", szfilename);  // Note scanf does not accept space within file names, use fgets instead
        return 0;
    }

    int open_audio_file(const char *szfilename)
    {
        if (szfilename == NULL)
        {
            printf("File name specified: NULL\n");
            return -1;
        }
        string sfilename;
        sfilename = szfilename;
        pio->setfilename(sfilename);
        return pio->open();
    }

    int close_audio_file(FILE *fp)
    {
        return pio->close();
    }

    int read_audio_file_header(uint8_t *header_data, uint8_t *audio_data)
    {
        size_t read_sz = pio->read((char *)header_data, sizeof(uint8_t), HEADER_LEN);

        if (read_sz != HEADER_LEN)
        {
            printf("Unable to read header, file may be partially truncated: byte read  %d\n", read_sz);
            return -1;
        }


        return 0;
    }

    int validate_pcm_wav_file(uint8_t *header_data)
    {
        audio_file_header_t *audio_header;

        audio_header = (audio_file_header_t *)header_data;

        if (audio_header->header_signature != RIFF_SIGNATURE)
        {
            printf("Error: Not a WAV file\n"); // technically it is not a RIFF file
            return -1;
        }

        if (audio_header->header_signature != RIFF_SIGNATURE)
        {
            printf("Error: Not a WAV file\n"); // technically it is not a RIFF file
            return -1;
        }

        if (audio_header->fmt_type != PCM_TYPE)
        {
            printf("Error: Not a PCM formatted type file\n"); // it is not a PCM type file
            return -1;
        }

        return 0;
    }


    int print_header_data(uint8_t *header_data_l)
    {
        audio_file_header_t *header_data;
        char *temp_sig;

        header_data = (audio_file_header_t *)header_data_l;
        temp_sig = (char *)&header_data->header_signature;
        printf("Header Signature: %x (%c%c%c%c) \n", header_data->header_signature,
               temp_sig[0], temp_sig[1], temp_sig[2], temp_sig[3]);

        printf("File Size: %d\n", header_data->file_size);

        temp_sig = (char *)&header_data->file_type;

        printf("File Type: %x (%c%c%c%c)\n", header_data->file_type, temp_sig[0], temp_sig[1], temp_sig[2], temp_sig[3]);

        temp_sig = (char *)&header_data->fmt_chunk_signature;

        printf("Fmt signature: %x (%c%c%c)\n", header_data->fmt_chunk_signature, temp_sig[0], temp_sig[1], temp_sig[2]);
        printf("Fmt length: %d\n", header_data->fmt_length);
        printf("Fmt type: %d\n", header_data->fmt_type);
        printf("No of channels: %d\n", header_data->no_of_channels);

        printf("Sample Rate %d\n", header_data->sample_rate);

        printf("Sample Byte Rate: %d\n", header_data->sample_byte_rate);

        printf("Block align: %d\n", header_data->block_align);

        printf("Bits per sample: %d\n", header_data->bits_per_sample);

        temp_sig = (char *)&header_data->data_chunk_signature;

        printf("Data chunk signature: %x  (%c%c%c%c) \n", header_data->data_chunk_signature,
               temp_sig[0], temp_sig[1], temp_sig[2], temp_sig[3]);

        printf("Data length: %d\n", header_data->data_length);

        return 0;
    }
};



int main(int argc, char* argv[])
{
    char szfilename[MAX_FILENAME_SIZE];
    uint8_t header_data[HEADER_LEN];
    uint8_t audio_data[HEADER_LEN];
    IOFSImpl *pIO;
    pIO = new IOFSImpl();

    WavParser wp(pIO);

    if (wp.accept_file_name(szfilename))
        return -1;

    if (wp.open_audio_file(szfilename))
        return -1;

    if (wp.read_audio_file_header(header_data, audio_data))
        return -1;

    if (wp.validate_pcm_wav_file(header_data))
        return -1;

    wp.print_header_data(header_data);

    return 0;
}


