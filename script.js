// Função para abrir o popup
function openPopup(formType) {
    const popup = document.getElementById('popup');
    const loginForm = document.getElementById('login-form');
    const signupForm = document.getElementById('signup-form');

    // Exibe o popup
    popup.style.display = 'flex';

    // Alterna entre o formulário de login e cadastro
    if (formType === 'login') {
        loginForm.style.display = 'block';
        signupForm.style.display = 'none';
    } else if (formType === 'signup') {
        loginForm.style.display = 'none';
        signupForm.style.display = 'block';
    }
}

// Função para fechar o popup
function closePopup() {
    const popup = document.getElementById('popup');
    popup.style.display = 'none';
}

// Garante que o popup será fechado se o usuário clicar fora dele
window.addEventListener('click', function(event) {
    const popup = document.getElementById('popup');
    if (event.target === popup) {
        closePopup();
    }
});
