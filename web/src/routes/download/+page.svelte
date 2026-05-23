<script lang="ts">
	import { fade } from 'svelte/transition';

	// Svelte 5 state for the copy button
	let copied = $state(false);

	const copyInstallCommand = () => {
		navigator.clipboard.writeText('curl -sL trace.sh | sh');
		copied = true;
		setTimeout(() => (copied = false), 2000);
	};
</script>

<main class="min-h-screen w-full bg-white px-6 py-20 selection:bg-emerald-100/30">
	<article class="mx-auto max-w-3xl">
		<div class="mb-12 border-b border-zinc-200 pb-8">
			<div class="flex items-center gap-4">
				<h1 class="text-4xl font-black tracking-[0.2em] text-black uppercase">Downloads</h1>
			</div>
		</div>

		<div class="space-y-12">
			<section class="relative">
				<svg
					fill="#000000"
					version="1.1"
					id="Layer_1"
					xmlns="http://www.w3.org/2000/svg"
					xmlns:xlink="http://www.w3.org/1999/xlink"
					viewBox="0 0 304.998 304.998"
					xml:space="preserve"
					class="h-6 w-6"
				>
					<path
						id="XMLID_92_"
						d="M274.659,244.888c-8.944-3.663-12.77-8.524-12.4-15.777c0.381-8.466-4.422-14.667-6.703-17.117
		c1.378-5.264,5.405-23.474,0.004-39.291c-5.804-16.93-23.524-42.787-41.808-68.204c-7.485-10.438-7.839-21.784-8.248-34.922
		c-0.392-12.531-0.834-26.735-7.822-42.525C190.084,9.859,174.838,0,155.851,0c-11.295,0-22.889,3.53-31.811,9.684
		c-18.27,12.609-15.855,40.1-14.257,58.291c0.219,2.491,0.425,4.844,0.545,6.853c1.064,17.816,0.096,27.206-1.17,30.06
		c-0.819,1.865-4.851,7.173-9.118,12.793c-4.413,5.812-9.416,12.4-13.517,18.539c-4.893,7.387-8.843,18.678-12.663,29.597
		c-2.795,7.99-5.435,15.537-8.005,20.047c-4.871,8.676-3.659,16.766-2.647,20.505c-1.844,1.281-4.508,3.803-6.757,8.557
		c-2.718,5.8-8.233,8.917-19.701,11.122c-5.27,1.078-8.904,3.294-10.804,6.586c-2.765,4.791-1.259,10.811,0.115,14.925
		c2.03,6.048,0.765,9.876-1.535,16.826c-0.53,1.604-1.131,3.42-1.74,5.423c-0.959,3.161-0.613,6.035,1.026,8.542
		c4.331,6.621,16.969,8.956,29.979,10.492c7.768,0.922,16.27,4.029,24.493,7.035c8.057,2.944,16.388,5.989,23.961,6.913
		c1.151,0.145,2.291,0.218,3.39,0.218c11.434,0,16.6-7.587,18.238-10.704c4.107-0.838,18.272-3.522,32.871-3.882
		c14.576-0.416,28.679,2.462,32.674,3.357c1.256,2.404,4.567,7.895,9.845,10.724c2.901,1.586,6.938,2.495,11.073,2.495
		c0.001,0,0,0,0.001,0c4.416,0,12.817-1.044,19.466-8.039c6.632-7.028,23.202-16,35.302-22.551c2.7-1.462,5.226-2.83,7.441-4.065
		c6.797-3.768,10.506-9.152,10.175-14.771C282.445,250.905,279.356,246.811,274.659,244.888z M124.189,243.535
		c-0.846-5.96-8.513-11.871-17.392-18.715c-7.26-5.597-15.489-11.94-17.756-17.312c-4.685-11.082-0.992-30.568,5.447-40.602
		c3.182-5.024,5.781-12.643,8.295-20.011c2.714-7.956,5.521-16.182,8.66-19.783c4.971-5.622,9.565-16.561,10.379-25.182
		c4.655,4.444,11.876,10.083,18.547,10.083c1.027,0,2.024-0.134,2.977-0.403c4.564-1.318,11.277-5.197,17.769-8.947
		c5.597-3.234,12.499-7.222,15.096-7.585c4.453,6.394,30.328,63.655,32.972,82.044c2.092,14.55-0.118,26.578-1.229,31.289
		c-0.894-0.122-1.96-0.221-3.08-0.221c-7.207,0-9.115,3.934-9.612,6.283c-1.278,6.103-1.413,25.618-1.427,30.003
		c-2.606,3.311-15.785,18.903-34.706,21.706c-7.707,1.12-14.904,1.688-21.39,1.688c-5.544,0-9.082-0.428-10.551-0.651l-9.508-10.879
		C121.429,254.489,125.177,250.583,124.189,243.535z M136.254,64.149c-0.297,0.128-0.589,0.265-0.876,0.411
		c-0.029-0.644-0.096-1.297-0.199-1.952c-1.038-5.975-5-10.312-9.419-10.312c-0.327,0-0.656,0.025-1.017,0.08
		c-2.629,0.438-4.691,2.413-5.821,5.213c0.991-6.144,4.472-10.693,8.602-10.693c4.85,0,8.947,6.536,8.947,14.272
		C136.471,62.143,136.4,63.113,136.254,64.149z M173.94,68.756c0.444-1.414,0.684-2.944,0.684-4.532
		c0-7.014-4.45-12.509-10.131-12.509c-5.552,0-10.069,5.611-10.069,12.509c0,0.47,0.023,0.941,0.067,1.411
		c-0.294-0.113-0.581-0.223-0.861-0.329c-0.639-1.935-0.962-3.954-0.962-6.015c0-8.387,5.36-15.211,11.95-15.211
		c6.589,0,11.95,6.824,11.95,15.211C176.568,62.78,175.605,66.11,173.94,68.756z M169.081,85.08
		c-0.095,0.424-0.297,0.612-2.531,1.774c-1.128,0.587-2.532,1.318-4.289,2.388l-1.174,0.711c-4.718,2.86-15.765,9.559-18.764,9.952
		c-2.037,0.274-3.297-0.516-6.13-2.441c-0.639-0.435-1.319-0.897-2.044-1.362c-5.107-3.351-8.392-7.042-8.763-8.485
		c1.665-1.287,5.792-4.508,7.905-6.415c4.289-3.988,8.605-6.668,10.741-6.668c0.113,0,0.215,0.008,0.321,0.028
		c2.51,0.443,8.701,2.914,13.223,4.718c2.09,0.834,3.895,1.554,5.165,2.01C166.742,82.664,168.828,84.422,169.081,85.08z
		 M205.028,271.45c2.257-10.181,4.857-24.031,4.436-32.196c-0.097-1.855-0.261-3.874-0.42-5.826
		c-0.297-3.65-0.738-9.075-0.283-10.684c0.09-0.042,0.19-0.078,0.301-0.109c0.019,4.668,1.033,13.979,8.479,17.226
		c2.219,0.968,4.755,1.458,7.537,1.458c7.459,0,15.735-3.659,19.125-7.049c1.996-1.996,3.675-4.438,4.851-6.372
		c0.257,0.753,0.415,1.737,0.332,3.005c-0.443,6.885,2.903,16.019,9.271,19.385l0.927,0.487c2.268,1.19,8.292,4.353,8.389,5.853
		c-0.001,0.001-0.051,0.177-0.387,0.489c-1.509,1.379-6.82,4.091-11.956,6.714c-9.111,4.652-19.438,9.925-24.076,14.803
		c-6.53,6.872-13.916,11.488-18.376,11.488c-0.537,0-1.026-0.068-1.461-0.206C206.873,288.406,202.886,281.417,205.028,271.45z
		 M39.917,245.477c-0.494-2.312-0.884-4.137-0.465-5.905c0.304-1.31,6.771-2.714,9.533-3.313c3.883-0.843,7.899-1.714,10.525-3.308
		c3.551-2.151,5.474-6.118,7.17-9.618c1.228-2.531,2.496-5.148,4.005-6.007c0.085-0.05,0.215-0.108,0.463-0.108
		c2.827,0,8.759,5.943,12.177,11.262c0.867,1.341,2.473,4.028,4.331,7.139c5.557,9.298,13.166,22.033,17.14,26.301
		c3.581,3.837,9.378,11.214,7.952,17.541c-1.044,4.909-6.602,8.901-7.913,9.784c-0.476,0.108-1.065,0.163-1.758,0.163
		c-7.606,0-22.662-6.328-30.751-9.728l-1.197-0.503c-4.517-1.894-11.891-3.087-19.022-4.241c-5.674-0.919-13.444-2.176-14.732-3.312
		c-1.044-1.171,0.167-4.978,1.235-8.337c0.769-2.414,1.563-4.91,1.998-7.523C41.225,251.596,40.499,248.203,39.917,245.477z"
					/>
				</svg>
				<div class="mb-4 flex items-center justify-between">
					<div class="flex items-center gap-3">
						<h2 class="text-xl font-bold tracking-widest text-black uppercase">Linux</h2>
					</div>
					<span
						class="rounded bg-emerald-100 px-2 py-1 text-xs font-bold tracking-widest text-emerald-800 uppercase"
						>Supported</span
					>
				</div>

				<div class="w-full">
					<span class="mb-2 block text-xs font-bold tracking-widest text-zinc-500 uppercase"
						>// Instant curl deployment</span
					>

					<button
						onclick={copyInstallCommand}
						class="group relative flex w-full items-center justify-between rounded border border-emerald-500/30 bg-zinc-100 px-5 py-4 text-left shadow-sm transition-all hover:border-emerald-700/70 hover:bg-emerald-50/50 focus:outline-none"
						aria-label="Copy Linux install command"
					>
						<div class="flex items-center gap-4 overflow-x-auto whitespace-nowrap">
							<span class="text-zinc-500">$</span>
							<span class="font-bold text-black">curl -sL trace.sh | sh</span>
						</div>

						<div class="ml-4 flex shrink-0 items-center justify-center">
							{#if copied}
								<span
									transition:fade={{ duration: 150 }}
									class="text-xs font-bold tracking-widest text-emerald-700 uppercase">Copied</span
								>
							{:else}
								<span
									transition:fade={{ duration: 150 }}
									class="text-xs tracking-widest text-zinc-500 uppercase transition-colors group-hover:text-emerald-700"
									>Copy</span
								>
							{/if}
						</div>
					</button>
					<span class="mt-2 block text-xs text-zinc-500"
						>Targets: Debian, Ubuntu, Arch, RHEL, Alpine</span
					>
				</div>
			</section>

			<section class="relative opacity-60">
				<div class="mb-4 flex items-center justify-between">
					<div class="flex items-center gap-3">
						<svg
							class="h-6 w-6 text-zinc-500"
							viewBox="0 0 448 512"
							fill="currentColor"
							aria-hidden="true"
						>
							<path
								d="M0 93.6l183.2-25.3v177.4H0V93.6zm0 324.6l183.2 25.3V268.4H0v149.8zm203.8 28.1L448 480V268.4H203.8v177.9zm0-380.6v180.1H448V32L203.8 65.7z"
							/>
						</svg>
						<h2 class="text-xl font-bold tracking-widest text-zinc-600 uppercase">Windows</h2>
					</div>
					<span
						class="rounded bg-zinc-200 px-2 py-1 text-xs font-bold tracking-widest text-zinc-600 uppercase"
						>In Development</span
					>
				</div>

				<div class="w-full">
					<span class="mb-2 block text-xs font-bold tracking-widest text-zinc-400 uppercase"
						>// Native executable pending</span
					>

					<div
						class="flex w-full items-center gap-4 rounded border border-dashed border-zinc-300 bg-zinc-50 px-5 py-4 text-zinc-400"
					>
						<span>></span>
						<span>trace: target 'x86_64-windows' is scheduled for next release</span>
					</div>
					<span class="mt-2 block text-xs text-zinc-400"
						>Current workaround: Run via WSL2 (Windows Subsystem for Linux)</span
					>
				</div>
			</section>

			<section class="relative opacity-50">
				<div class="mb-4 flex items-center justify-between">
					<div class="flex items-center gap-3">
						<svg
							class="h-6 w-6 text-zinc-400"
							viewBox="0 0 384 512"
							fill="currentColor"
							aria-hidden="true"
						>
							<path
								d="M318.7 268.7c-.2-36.7 16.4-64.4 50-84.8-18.8-26.9-47.2-41.7-84.7-44.6-35.5-2.8-74.3 20.7-88.5 20.7-15 0-49.4-19.7-76.4-19.7C63.3 141.2 4 184.8 4 273.5q0 39.3 14.4 81.2c12.8 36.7 59 126.7 107.2 125.2 25.2-.6 43-17.9 75.8-17.9 31.8 0 48.3 17.9 76.4 17.9 48.6-.7 90.4-82.5 102.6-119.3-65.2-30.7-61.7-90-61.7-91.9zm-56.6-164.2c27.3-32.4 24.8-61.9 24-72.5-24.1 1.4-52 16.4-67.9 34.9-17.5 19.8-27.8 44.3-25.6 71.9 26.1 2 49.9-11.4 69.5-34.3z"
							/>
						</svg>
						<h2
							class="text-xl font-bold tracking-widest text-zinc-400 uppercase line-through decoration-zinc-300"
						>
							macOS
						</h2>
					</div>
					<span
						class="rounded bg-red-50 px-2 py-1 text-xs font-bold tracking-widest text-red-600 uppercase"
						>Unsupported</span
					>
				</div>

				<div class="w-full">
					<div
						class="flex w-full items-center gap-4 rounded border border-zinc-200 bg-white px-5 py-4 text-zinc-400"
					>
						<span class="text-red-400">✗</span>
						<span>trace: target 'darwin' is not planned</span>
					</div>
					<span class="mt-2 block text-xs text-zinc-400"
						>No native support planned for Apple Silicon or Intel Macs.</span
					>
				</div>
			</section>
		</div>
	</article>
</main>
