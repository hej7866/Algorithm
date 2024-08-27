using System;
using System.Collections.Generic;

public class CartesianCoordinate
{
    public int X = 0;
    public int Y = 0;

    public bool IsSame(CartesianCoordinate other)
    {
        return X == other.X && Y == other.Y;
    }
}

public class LineInformation
{
    public CartesianCoordinate Point1 = new CartesianCoordinate();
    public CartesianCoordinate Point2 = new CartesianCoordinate();

    public double Slope
    {
        get
        {
            return (double)(Point2.Y - Point1.Y) / (Point2.X - Point1.X);
        }
    }

    public LineInformation(int x1, int y1, int x2, int y2)
    {
        Point1.X = x1;
        Point1.Y = y1;
        Point2.X = x2;
        Point2.Y = y2;
    }

    public bool IsPointShared(LineInformation other)
    {
        return Point1.IsSame(other.Point1) || Point1.IsSame(other.Point2) ||
            Point2.IsSame(other.Point1) || Point2.IsSame(other.Point2);
    }

    public bool IsParallel(LineInformation other)
    {
        return Slope == other.Slope;
    }
}

public class Solution
{
    public int solution(int[,] dots)
    {
        List<LineInformation> lines = new List<LineInformation>();

        for (int i = 0; i < dots.GetLength(0); i++)
        {
            for (int j = i + 1; j < dots.GetLength(0); j++)
            {
                var lineInfo = new LineInformation(dots[i, 0], dots[i, 1], dots[j, 0], dots[j, 1]);

                lines.Add(lineInfo);
            }
        }

        for (int i = 0; i < lines.Count; i++)
        {
            for (int j = i + 1; j < lines.Count; j++)
            {
                if (!lines[i].IsPointShared(lines[j]) && lines[i].IsParallel(lines[j]))
                {
                    return 1;
                }
            }
        }

        return 0;
    }
}