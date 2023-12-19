#pragma once
#include <chrono>
#include <functional>
namespace unag::benchmark
{
	class Benchmarker
	{
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
		double m_AverageTotal{};
		int m_Amount{};

	public:
		void StartBenchmark()
		{
			m_StartTime = std::chrono::high_resolution_clock::now();
		}

		double StopBenchmark()
		{
			const auto end_timepoint = std::chrono::high_resolution_clock::now();
			const auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTime).time_since_epoch().count();
			const auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timepoint).time_since_epoch().count();

			const auto duration = end - start;
			const double ms = static_cast<double>(duration) * 0.001;

			m_AverageTotal += ms;
			++m_Amount;

			return ms;
		}

		double GetAverageMs() const
		{
			return m_AverageTotal / m_Amount;
		}

		double AutoBench(const std::function<void()>& test, int amount = 10)
		{
			for (int i{}; i < amount; ++i)
			{
				StartBenchmark();
				test();
				StopBenchmark();
			}
			return GetAverageMs();
		}
	};
}