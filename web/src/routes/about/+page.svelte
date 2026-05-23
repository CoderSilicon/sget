<script lang="ts">
    import logo from '$lib/assets/favicon.svg';
</script>

<main class="mx-auto max-w-2xl px-6 py-16 md:py-24">
    <div class="mb-12 flex items-center gap-4">
        <img src={logo} alt="Trace Logo" class="h-12 w-12 object-contain" />
        <h1 class="text-3xl font-black uppercase tracking-[0.2em] text-black">
            he Origin
        </h1>
    </div>

    <div class="space-y-6 text-base  leading-relaxed text-zinc-600">
        <p>
            Trace used to be called <strong>"LinkBytes"</strong>. It was just a humble web-based link shortener which I developed in my early days; a tiny side project born out of pure tutorials by 
            <a href="https://github.com/CoderSilicon" target="_blank" rel="noopener noreferrer" class="font-bold text-black transition-colors hover:text-zinc-500">
                @codersilicon
            </a>.
        </p>

        <p>
            But as I grew as a developer, my tools also grew with me. My workflow shifted away from pure web to deep into systems. A standard web interface just didn't made sense anymore. I needed something frictionless. But I also couldn't abandon this.
        </p>

        <p>
            So, I redesigned LinkBytes's core motive. I stripped away the visual fluff, rebuilt the core engine, and forged it into a lightning-fast CLI tool. Trace is the reincarnation of <strong>"LinkBytes"</strong> that early spark—colder, sharper, and built entirely for the command line.
        </p>
    </div>
</main>