; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x39456 (bvmul arg0_0 arg1_8)))
(let ((?x71004 (bvmul (_ bv4294967295 32) ?x39456)))
(let ((?x22936 (bvmul arg0_0 arg1_1)))
(let ((?x61507 (bvadd ?x22936 ?x71004)))
(and (distinct ?x61507 (_ bv0 32)) true))))))
(check-sat)
