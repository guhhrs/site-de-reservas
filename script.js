function moveSlide(button, direction) {
    let carousel = button.parentElement.querySelector('.carousel-images');
    let images = carousel.querySelectorAll('img');
    let totalSlides = images.length;
    let currentIndex = parseInt(carousel.getAttribute('data-index')) || 0;

    currentIndex = (currentIndex + direction + totalSlides) % totalSlides;
    carousel.setAttribute('data-index', currentIndex);

    // Ajuste para garantir que apenas uma imagem apareça por vez
    let imageWidth = button.parentElement.clientWidth;
    carousel.style.transform = `translateX(-${currentIndex * imageWidth}px)`;
}

// Garante que o carrossel inicie corretamente
document.addEventListener("DOMContentLoaded", function () {
    document.querySelectorAll('.carousel-images').forEach(carousel => {
        carousel.setAttribute('data-index', 0);
        carousel.style.transform = 'translateX(0)';
    });
});
