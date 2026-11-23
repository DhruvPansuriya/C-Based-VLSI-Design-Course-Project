; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x709394 (bvmul arg0_16 arg2_5)))
(let ((?x711265 (bvmul (_ bv4294967295 32) ?x709394)))
(let ((?x100 (bvmul arg0_16 arg2_4)))
(let ((?x710567 (bvadd ?x100 ?x711265)))
(and (distinct ?x710567 (_ bv0 32)) true))))))
(check-sat)
