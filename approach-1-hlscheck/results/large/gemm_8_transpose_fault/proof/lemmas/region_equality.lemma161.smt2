; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_55 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg1_62 () (_ BitVec 32))
(assert
 (let ((?x75248 (bvmul arg0_23 arg1_55)))
(let ((?x68557 (bvmul (_ bv4294967295 32) ?x75248)))
(let ((?x39386 (bvmul arg0_23 arg1_62)))
(let ((?x67026 (bvadd ?x39386 ?x68557)))
(and (distinct ?x67026 (_ bv0 32)) true))))))
(check-sat)
