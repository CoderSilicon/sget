![sget](web/src/lib/assets/favicon.png)
# sget

> **The CLI data-tracer.** A smart, advanced web scraper and data extractor built on top of `curl`.

[![Built by CoderSilicon](https://img.shields.io/badge/Built%20by-CoderSilicon-004d40.svg?style=flat-square)](https://github.com/CoderSilicon)
[![License: MIT](https://img.shields.io/badge/License-MIT-teal.svg?style=flat-square)](LICENSE)


---

## ⚡ The Core Philosophy

sget operates directly on raw HTTP streams. It treats the web as a queryable data pipeline rather than a visual canvas, making it incredibly lightweight and lightning-fast.

* **`curl`-Powered Core:** Built straight on top of the industry standard for network requests. If `curl` can reach it, sget can extract from it.
* **Zero Engine Overhead:** No Chromium instances, no heavy JS evaluation loops, and zero memory leaks. Just pure data parsing.
* **Unix-Pipeline Native:** Seamlessly fits into your existing workflow. Pipe HTML/JSON into sget, or pipe sget's structured output straight into `jq`, `grep`, or local files.

---

## 🏗️ Architecture Flow


```

[ Target Webpage ]
│
▼  (Optimized HTTP Fetch)
┌───────┐
│ curl  │
└───────┘
│
▼  (Raw Data Stream)
┌───────┐
│ sget │ ──► [ Extraction Engine: CSS Selectors / XPath / Regex ]
└───────┘
│
▼  (Structured Output Flush)
[ JSON / CSV / Text ] ──► Pipe to next tool (e.g., jq, redirect to file)

```

1. **The Fetch:** sget utilizes native network optimization layers via `curl` for highly stable, low-level HTTP requests.
2. **The Stream:** The target payload is fed instantly into sget's memory-efficient stream parser without downloading unnecessary visual assets.
3. **The Extraction:** Your declarative filters (CSS tags, XPath nodes, or Regex boundaries) parse the DOM structure instantly.
4. **The Output:** Structured data is flushed to `stdout` in your format of choice, completely ready for automated consumption.



## 🛠️ Stack & Mechanics

| Layer | Engine/Protocol | Purpose |
| :--- | :--- | :--- |
| **Network** | [curl](https://curl.se/) | Low-overhead HTTP transfer, custom headers, proxy handling, and cookie jars. |
| **Parsing** | C/Go Native Engine | High-performance CSS selectors and XPath element targeting. |
| **Formatting** | Stream Serializer | Instant conversion of extracted elements into structured `JSON`, `CSV`, or raw text. |
| **Environment** | POSIX CLI | Built to run standalone inside any Linux, macOS, or Windows terminal. |



## 🔒 Optimization & Speed

sget is engineered from the ground up for high-performance automation:
* **Minimal Memory Footprint:** Uses a fraction of the RAM required by headless browsers (Puppeteer/Playwright).
* **Parallel Scrapes:** Launch multiple data tracing threads concurrently without melting your CPU.
* **Bypass Anti-Bot:** Native integration for rapid User-Agent rotation, custom request delays, and upstream proxy chains.



<br />

<div align="center">
  <sub>Built with 💻 by <a href="https://github.com/CoderSilicon">CoderSilicon</a></sub>
  <br />
  <em>"It is always better to differ from others."</em>
</div>

