// javascript:(function(){console.log('🚀 开始添加测试用例...');const w=ms=>new Promise(r=>setTimeout(r,ms));async function run(){const items=[];document.querySelectorAll('.group.flex.cursor-pointer, .ant-list-item').forEach(el=>{const text=el.textContent;if((text.includes('解答错误')||text.includes('超出输出限制'))&&!text.includes('通过')&&!text.includes('Accepted')){items.push(el);}});console.log(`找到 ${items.length} 个错误提交`);let added=0;for(let i=0;i<Math.min(items.length,10);i++){console.log(`处理 ${i+1}/${Math.min(items.length,10)}`);items[i].click();await w(1500);const btn=document.querySelector('.testcaseAsInputClass')?.closest('.cursor-pointer');if(btn){btn.click();added++;console.log('✅ 已添加');}const closeBtn=document.querySelector('[data-layout-path*="button/close"]');if(closeBtn)closeBtn.click();await w(1000);}console.log(`完成! 添加了 ${added} 个测试用例`);alert(`添加了 ${added} 个测试用例`);}run().catch(e=>console.error(e));})();

// 一键添加错误提交的测试用例
javascript:(function(){
    console.log('🚀 开始添加测试用例...');
    const w = ms => new Promise(r => setTimeout(r, ms));
    
    async function run() {
        // 获取错误提交
        const items = [];
        document.querySelectorAll('.group.flex.cursor-pointer, .ant-list-item').forEach(el => {
            const text = el.textContent;
            if ((text.includes('解答错误') || text.includes('超出输出限制')) && 
                !text.includes('通过') && !text.includes('Accepted')) {
                items.push(el);
            }
        });
        
        console.log(`找到 ${items.length} 个错误提交`);
        
        let added = 0;
        
        for (let i = 0; i < Math.min(items.length, 10); i++) {
            console.log(`处理 ${i+1}/${Math.min(items.length, 10)}`);
            
            items[i].click();
            await w(1500);
            
            // 点击添加到测试用例
            const btn = document.querySelector('.testcaseAsInputClass')?.closest('.cursor-pointer');
            if (btn) {
                btn.click();
                added++;
                console.log('✅ 已添加');
            }
            
            // 关闭
            const closeBtn = document.querySelector('[data-layout-path*="button/close"]');
            if (closeBtn) closeBtn.click();
            
            await w(1000);
        }
        
        console.log(`完成! 添加了 ${added} 个测试用例`);
        alert(`添加了 ${added} 个测试用例`);
    }
    
    run().catch(e => console.error(e));
})();
