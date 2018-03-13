﻿namespace RagnarokReplay
{
    public class Chunk
    {
        public int Id { get; set; }
        public int Length { get; set; }
        public byte[] Data { get; set; }
        public int Time { get; set; }
        public ushort Header { get; set; }
    }
}
